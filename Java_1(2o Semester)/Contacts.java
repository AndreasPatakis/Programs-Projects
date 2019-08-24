package contacts;


public class Contacts{
    private String first_name;
    private String last_name;
    private String number;

    //Setters
    public void set_first_name(String name){
      this.first_name = name;
    }
    public void set_last_name(String name){
      this.last_name = name;
    }
    public void set_number(String number){
      this.number = number;
    }

    //Getters
    public String get_first_name(){
      return first_name;
    }
    public String get_last_name(){
      return last_name;
    }
    public String get_number(){
      return number;
    }

    public Contacts(String first,String last,String number){
        this.first_name = first;
        this.last_name = last;
        this.number = number;
    }
    public Contacts(){
      this.first_name = "";
      this.last_name = "";
      this.number = "0";
    }

}
