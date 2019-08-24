import java.util.Random;
import java.util.Scanner;
import java.util.concurrent.ThreadLocalRandom;
import java.util.concurrent.Semaphore;

public class Erwtima_b {

    public static boolean contains(final Integer[] array, final int key) {
        for(int i=0;i<array.length;i++){
            if(array[i] == null){
                return false;
            } else if(array[i] ==  key){
                return true;
            }
        } return false;

    }

    public static void main(String args[]) {


        int arrayWidth = 0;

        while (arrayWidth <= 0) {
            Scanner get = new Scanner(System.in);
            System.out.println("Give an integer, greater than zero.\n");
            arrayWidth = get.nextInt();
            System.out.println("\n");

        }

        Integer[] myArray = new Integer[arrayWidth];

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

        // Allazei ta misa stoixeia tou array me tuxaious arithmous

              try{available.acquire();}
              catch(InterruptedException e){System.out.println("Error");};

              int t1result = 0;

                for(int i=0;i<finalArrayWidth/2;i++){

                        int temp = random.nextInt(finalArrayWidth);
                        while(contains(myArray,temp)) {
                            temp = random.nextInt(finalArrayWidth);
                        }
                        myArray[temp] = random.nextInt(200) - 100;
                }

        //Ypologizei to athrisma meta tis allages (erwtima b')

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

        // Allazei ta misa stoixeia tou array me tuxaious arithmous

                try{available.acquire();}
                catch(InterruptedException e){System.out.println("Error");};

                int t2result = 1;

                for(int i=0;i<finalArrayWidth/2;i++){

                    int temp = random.nextInt(finalArrayWidth);
                    while(contains(myArray,temp)) {
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
        }System.out.println("\n");

        T1.start();
        T2.start();
        T3.start();
        try {
            T1.join();
            T2.join();
            T3.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        T4.start();

    }

}
