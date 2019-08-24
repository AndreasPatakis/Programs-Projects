import java.util.*;
import java.util.Random;
import java.util.Scanner;
import java.util.ArrayList;
import java.io.*;
import contacts.Contacts;


public class ErgasiaJava {

  public static void starting_info(){
    System.out.println("Please select one of the following options.\n");
    for(int i=0;i<=22;i++){
      System.out.print("- ");
    }
    System.out.println("\n");
    System.out.println(
    "1.     Show all contacts.\n"+
    "2.     Add a new contact.\n"+
    "3.     Search contacts by name.\n"+
    "4.     Search contacts by phone number.\n"+
    "5.     Edit contact(Give phone number)\n"+
    "6.     Delete contact(By name)\n"+
    "7.     Exit.\n\n\n");
  }

  public static int choose_option(){
    int choice;
    Scanner get = new Scanner(System.in);
    while(true){
      try{
        choice = get.nextInt();
        if(choice <= 0 || choice > 7){
          System.out.print("You must choose one number betwen 1 and 7.\n");
          continue;
        }
        break;
      }
      catch(InputMismatchException ex){
        System.out.print("You must choose one number between 1 and 7.\n");
        get.nextLine();
      }
    }
    return choice;
  }

  public static int search_byname(String first, String last){
    List<Contacts> contact = data_read();
    for(int i = 0;i<contact.size();i++){
       if( (contact.get(i).get_first_name()).equals(first) && (contact.get(i).get_last_name()).equals(last) ){
         return i;
       }
    }
    return -1;
  }

  public static int search_bynumber(String num){
    List<Contacts> contact = data_read();
    for(int i = 0;i<contact.size();i++){
       if( (contact.get(i).get_number()).equals(num) ){
         return i;
       }
    }
    return -1;
  }

  public static void print_i(int choice){
    int i = 0;
    String line;
    try (BufferedReader br = new BufferedReader(new FileReader("./Contacts.csv"))) {
    while ((line = br.readLine()) != null) {
      if( i == choice ){
        System.out.println(line+"\n");
        break;
      }else{
        i += 1;
      }
     }
    }catch (FileNotFoundException e) {
    // exception handling
    } catch (IOException e) {
    // exception handling
    }
  }


  public static boolean delete_contact(String first,String last){
    int toEdit;
    List<Contacts> contact_list = data_read();
    toEdit = search_byname(first,last);
    if(toEdit != -1){
      System.out.println("You want to delete the following contact:\n"+
                         contact_list.get(toEdit).get_first_name()+
                         " "+contact_list.get(toEdit).get_last_name()+
                         " "+contact_list.get(toEdit).get_number()+"\n");
      contact_list.remove(contact_list.get(toEdit));
      for(int i = 0;i<contact_list.size();i++){
        if(i == 0){
          data_write(contact_list.get(i).get_first_name(),
                     contact_list.get(i).get_last_name(),
                     contact_list.get(i).get_number(),false);
        }else{
          data_write(contact_list.get(i).get_first_name(),
                     contact_list.get(i).get_last_name(),
                     contact_list.get(i).get_number(),true);
        }
      }
      return true;
    }
    return false;
  }





  public static boolean edit_contact(String number){
    Scanner get = new Scanner(System.in);
    String[] attributes = {"Give firstname: ","Give lastname: ","Give phonenumber"};
    String[] data = new String[3];
    int toEdit;
    List<Contacts> contact_list = data_read();
    toEdit = search_bynumber(number);
    if(toEdit != -1){
      System.out.println("You want to edit the following contact:\n"+
                         contact_list.get(toEdit).get_first_name()+
                         " "+contact_list.get(toEdit).get_last_name()+
                         " "+contact_list.get(toEdit).get_number()+"\n");
      System.out.println("Give new data for this contact: \n");
      for(int i = 0;i<attributes.length;i++){
        System.out.println(attributes[i]);
        data[i] = get.nextLine();
        while(data[i].isEmpty() || data[i] == " "){
          System.out.println("Attribute can't be empty\n"+
          attributes[i]+" again.\n");
          data[i] = get.nextLine();
        }
        System.out.println("\n");
      }
      contact_list.get(toEdit).set_first_name(data[0]);
      contact_list.get(toEdit).set_last_name(data[1]);
      contact_list.get(toEdit).set_number(data[2]);
      for(int i = 0;i<contact_list.size();i++){
        if(i == 0){
          data_write(contact_list.get(i).get_first_name(),
                     contact_list.get(i).get_last_name(),
                     contact_list.get(i).get_number(),false);
        }else{
          data_write(contact_list.get(i).get_first_name(),
                     contact_list.get(i).get_last_name(),
                     contact_list.get(i).get_number(),true);
        }
      }
      return true;
    }
    return false;
  }

  public static List<Contacts> data_read(){
    String line;
    String words[];
    List<Contacts> contacts_list = new ArrayList<Contacts>();
    try (BufferedReader br = new BufferedReader(new FileReader("./Contacts.csv"))) {
    while ((line = br.readLine()) != null) {
       words = line.split(",");
       contacts_list.add(new Contacts(words[0],words[1],words[2]));
     }
    }catch (FileNotFoundException e) {
    // exception handling
    } catch (IOException e) {
    // exception handling
    }
    return contacts_list;
  }

  public static boolean data_write(String first,String last, String num,boolean state){
    String contact;

    try(FileWriter fw = new FileWriter("./Contacts.csv", state);
    BufferedWriter bw = new BufferedWriter(fw);
    PrintWriter out = new PrintWriter(bw))
    {
      contact = first+","+last+","+num;
      if(state){
        bw.write("\n"+contact);
      }else{
        bw.write(contact);
      }
      bw.close();
    } catch (IOException e) {
       return false;
    }
    return true;
  }

  public static boolean selected_option(int choice){
    boolean next = false;
    int found;
    List<Contacts> contacts;
    String[] attributes = {"Give firstname: ","Give lastname: ","Give phonenumber"};
    String[] data;
    Scanner get = new Scanner(System.in);
    String input;
    switch(choice){
      case 1:

        contacts = data_read();
        System.out.println("FirstName   LastName     PhoneNumber\n\n");
        for(int i = 0;i<contacts.size();i++){
          System.out.println(contacts.get(i).get_first_name()+"       "+
          contacts.get(i).get_last_name()+"         "+contacts.get(i).get_number());
        }
        System.out.println("\n\n");
        next = true;
        break;


      case 2:

        data = new String[3];
        System.out.println("Create new conctact: \n");
        for(int i = 0;i<attributes.length;i++){
          System.out.println(attributes[i]);
          data[i] = get.nextLine();
          while(data[i].isEmpty() || data[i] == " "){
            System.out.println("Attribute can't be empty\n"+
            attributes[i]+" again.\n");
            data[i] = get.nextLine();
          }
          System.out.println("\n");
        }
        if(data_write(data[0],data[1],data[2],true)){
          System.out.println("Contact created succesfully!\n");
        }else{
          System.out.println("Error occured, contact wasn't created, please try again.\n");
        }
        next = true;
        break;


      case 3:

        data = new String[2];
        System.out.println("Contact Search:\n");
        for(int i=0;i<2;i++){
          System.out.println(attributes[i]+"\n");
          data[i] = get.nextLine();
        }
        found = search_byname(data[0],data[1]);
        if (found != -1){
          print_i(found);
        }else{
          System.out.println("Contact not found\n");
        }
        next = true;
        break;


      case 4:

        String num;
        System.out.println("Contact Search:\n"+attributes[2]+"\n");
        num = get.nextLine();
        found = search_bynumber(num);
        if (found != -1){
          print_i(found);
        }else{
          System.out.println("Contact not found\n");
        }
        next = true;
        break;

      case 5:

        System.out.println("Give phone number: \n");
        input = get.nextLine();
        if(edit_contact(input)){
          System.out.println("Contact edited succesfully!\n");
        }else{
          System.out.println("Conctact not found.\n");
        }
        next = true;
        break;

      case 6:

        data = new String[2];
        for(int i=0;i<2;i++){
          System.out.println(attributes[i]);
          data[i] = get.nextLine();
        }
        if(delete_contact(data[0],data[1])){
          System.out.println("Contact deleted succesfully!\n");
        }else{
          System.out.println("Conctact not found.\n");
        }
        next = true;
        break;


      case 7:
        System.out.println("\nExiting Application...");
        next = false;
        break;
    }
    return next;
  }

  public static void main(String[] args){
    int choice;
    System.out.println("AddressBook Application\n");
    starting_info();
    choice = choose_option();

    while(selected_option(choice)){
      starting_info();
      choice = choose_option();
    }

  }
}
