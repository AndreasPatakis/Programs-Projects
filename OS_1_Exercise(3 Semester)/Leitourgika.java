import java.util.Random;
import java.util.Scanner;
import java.util.concurrent.ThreadLocalRandom;
import java.util.concurrent.Semaphore;


public class Leitourgika {

    public static boolean contains( Integer[] tempArray, final int key) {
        for(int i=0;i<tempArray.length;i++){
            if(tempArray[i] == null){
              tempArray[i] = key;

                break;
            } else if(tempArray[i] ==  key){
                return true;
            }
        }
        return false;
    }

    public static boolean threadsWaiting(Thread t1, Thread t2){
      if(t1.getState() == Thread.State.WAITING && t2.getState() == Thread.State.WAITING){
        return true;
      }return false;
    }

    public static void main(String args[]) {


        int arrayWidth = 0;

        while (arrayWidth <= 0) {
            Scanner get = new Scanner(System.in);
            System.out.println("Give an integer, greater than zero.\n");
            arrayWidth = get.nextInt();
            System.out.println("\n");

        }

        int myArray[] = new int [arrayWidth];

        Random random = new Random();

        for (int i = 0; i < arrayWidth; i++) {
            myArray[i] = random.nextInt(200)-100;
        }

        String threadsLocation[] = {"T1","T2","T3"};

        int threadsResults[] = new int[3];

        int finalArrayWidth = arrayWidth;

        final Semaphore available = new Semaphore(1, true);


        //Thread 1



        Thread T1 = new Thread() {
            public void run() {

                int t1result = 0;
        // Ypologizei to arxiko athroisma (erwtima a')

               for (int i = 0; i < finalArrayWidth; i++) {
                    System.out.println("T1 a': "+ myArray[i]);
                    t1result += myArray[i];
               }

                  threadsResults[0] = t1result;
                  System.out.println("Athroisma a': " + threadsResults[0] + " \n");

                  try{Thread.sleep(100);}
                  catch(InterruptedException e){System.out.println("Error");};
                synchronized(this){
                  try {
                  this.wait();
                  } catch (InterruptedException e){};
                }


        // Allazei ta misa stoixeia tou array me tuxaious arithmous

              try{available.acquire();}
              catch(InterruptedException e){System.out.println("Error");};
              Integer[] tempArray = new Integer[finalArrayWidth/2];

                for(int i=0;i<finalArrayWidth/2;i++){

                        int temp = random.nextInt(finalArrayWidth);

                        while(contains(tempArray,temp)) {
                            temp = random.nextInt(finalArrayWidth);
                        }
                        myArray[temp] = random.nextInt(200) - 100;
                }

        //Ypologizei to athrisma meta tis allages (erwtima b')

                t1result = 0;

                for (int i = 0; i < finalArrayWidth; i++) {
                    System.out.println("T1 b': "+ myArray[i]);
                    t1result += myArray[i];
                }

                threadsResults[0] = t1result;
                System.out.println("Athroisma b': " + threadsResults[0] + " \n");
                available.release();
            }
        };


        //Thread 2


        Thread T2 = new Thread() {
            public void run(){
        //Ypologizei to arxiko ginomeno (erwtima a')

                int t2result = 1;

                for (int i = 0; i < finalArrayWidth; i++) {
                    System.out.println("T2 a': "+ myArray[i]);
                    t2result *= myArray[i];
                }

                threadsResults[1] = t2result;
                System.out.println("Ginomeno a': " + threadsResults[1] + " \n");


                try{Thread.sleep(100);}
                catch(InterruptedException e){System.out.println("Error");};

                synchronized(this){
                  try {
                  this.wait();
                  } catch (InterruptedException e){};
                }

        // Allazei ta misa stoixeia tou array me tuxaious arithmous

                try{available.acquire();}
                catch(InterruptedException e){System.out.println("Error");};
                Integer[] tempArray = new Integer[finalArrayWidth/2];

                for(int i=0;i<finalArrayWidth/2;i++){

                    int temp = random.nextInt(finalArrayWidth);
                    while(contains(tempArray,temp)) {
                        temp = random.nextInt(finalArrayWidth);
                    }
                    myArray[temp] = random.nextInt(200) - 100;
                }


        //Ypologizei to ginomeno meta tis allages (erwtima b')

                for (int i = 0; i < finalArrayWidth; i++) {
                    System.out.println("T2 b': "+ myArray[i]);
                    t2result *= myArray[i];
                }

                threadsResults[1] = t2result;
                System.out.println("Ginomeno b': " + threadsResults[1] + " \n");
                available.release();
            }
        };


        //Thread 3


        Thread T3 = new Thread() {
            public void run() {
                int t3result = random.nextInt(2000)-1000;
                threadsResults[2] = t3result;
                System.out.println("O arithmos einai :" + threadsResults[2] + "\n");
            }
        };

        //Thread 4
        Thread T4 = new Thread(){
              public void run(){
                  int temp;
                  String s_temp;
                  boolean f = true;
                  while(f){
                      f = false;
                      for(int i=1;i<=threadsResults.length-1;i++) {
                          if (threadsResults[i - 1] < threadsResults[i]) {
                              temp = threadsResults[i - 1];
                              threadsResults[i - 1] = threadsResults[i];
                              threadsResults[i] = temp;
                              s_temp = threadsLocation[i - 1];
                              threadsLocation[i - 1] = threadsLocation[i];
                              threadsLocation[i] = s_temp;
                              f = true;
                          }
                      }
                  }


                  for(int i=0;i<=threadsResults.length-1;i++){
                      System.out.println(i+1+": "+threadsLocation[i]+" = "+threadsResults[i]+"\n");
                  }
              }
            };


        for (int i = 0; i < finalArrayWidth; i++) {
            System.out.println("Array : "+ myArray[i]);
        }

        T1.start();
        T2.start();
        T3.start();

        while(!threadsWaiting(T1,T2)){System.out.println("Waiting...");}
          T4.start();
          try {
              T4.join();
          } catch (InterruptedException e) {
              e.printStackTrace();
          }
          synchronized(T1) {T1.notify();}
          synchronized(T2) {T2.notify();}
          if(T3.getState().equals(Thread.State.TERMINATED)){
            System.out.println("TERMINATED");
            //T3.start();
          }


    }
}
