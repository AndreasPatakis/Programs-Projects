#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

 class tour{
public:
  int infos[4];
  tour(){
  fstream file;
  file.open("t103.txt");
  string line;
  int p=0;
  
  while(!file.eof()) {
        getline(file,line);
        istringstream iss(line);
        string word;

        if (p==0) {
        for(int i=0;i<=3;i++){
            iss >> word;
            infos[i]=stoi(word);}}
            else{break;}

        p+=1;}}};

  class hotel{
 public:
    int infos[7];
   hotel(){
   fstream file;
   file.open("t103.txt");
   string line;
   int p=0;
   while(!file.eof()) {
     getline(file,line);
     istringstream iss(line);
     string word;
     if (p==1) {
     for(int i=0;i<=6;i++){
         iss >> word;
         infos[i]=stoi(word);}}
         else if(p>1){break;}
     p+=1;}}};

     class diadromes{};




     int p1=0;
     class data{
     public:
       float infos[5];
       int open[7];
       int close[7];
       data(){
           int j1=-1;
           int j2=-1;
           p1+=1;

         int q=0;
         fstream file;
         file.open("t103.txt");
         string line;
         while(!file.eof()) {
           q+=1;
           getline(file,line);
           istringstream iss(line);
           string word;
           if(q!=1&&q!=2){
           if (q==p1){
             for(int y=0;y<=19;y++){
               iss >> word;
             if(y<=4){
                 infos[y]=stof(word);}
              else if(y!=5){
                 if(y%2==0){j1+=1;
                   open[j1]=stoi(word);}
                   else{j2+=1;
                     close[j2]=stoi(word);}
               }
       }break;}}}}};

       struct node
        {
          data x;
          node *next;
          //node* head;
        };
       node* head=new node;
       node* first=new node;


       void insert(data &sight){
         node *temp=new node;
         temp->x=sight;
         temp->next=NULL;
         head->next=temp;
         //cout<<head->next<<endl;
         //cout<<temp->data<<endl;
         head=temp;
       }


       void print(){
         node* temp=first;
         temp=temp->next;
         while(temp != NULL){
           cout<<temp->x.infos[0]<<endl;
           //cout<<temp->next<<endl;
           temp=temp->next;
         }
       }


int main(){
first=head;
tour tour_infos;
hotel hotel_infos;

data sight[91];

//cout<<sight[90].infos[0];
//cout<<sight[100].infos[0]<<endl;
for(int i=0;i<=73;i++){
insert(sight[i]);}

print();
//cout<<sight[164].close[0];
  //for (int i=0;i<=164;i++){
    //insert(sight[i]);}
    //cout<<endl;*/


return 0;
}
