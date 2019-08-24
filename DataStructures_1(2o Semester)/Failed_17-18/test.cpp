#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct node{
  int data;
  int depth;
  int greater;
  int lower;
  int difference;
  node *left=NULL;
  node *right=NULL;
  node *next=NULL;
  node *previous=NULL;
  node *constant=NULL;

};

node* head= new node;
node* start= new node;
node* nodenext= new node;
node* startnode= new node;


int n=1;
int maxdepthleft=0;
int maxdepthright=0;
int maxdepth=0;
int nodepos=0;
int maxnumber=0;


int depth(int v){
  head=start;
  int p=0;
  while(true){
    if (v==head->data) {
      break;
     }
    else if(v>head->data){
      head=head->right;
     }
    else{head=head->left;}
    p+=1;
   }
   return p;
 }


int givedata(int num){
 node *temp=new node;
 temp->data=num;
 while(true){
   if(temp->data>head->data){
     if(head->right==NULL){
       n+=1;
       head->right=temp;
       temp->depth=depth(temp->data);
       break;
     }else{
     head=head->right;
     }
   }
   else if(temp->data<head->data){
     if(head->left==NULL){
       n+=1;
       head->left=temp;
       temp->depth=depth(temp->data);
       break;}
     else{head=head->left;}
     }
   else{break;}
 }
 head=start;
 if(temp->data>head->data){
   if(temp->depth>maxdepthright){
     maxdepthright=temp->depth;
     maxnumber=temp->data;}
   }
 else if(temp->data<head->data){
   if(temp->depth>maxdepthleft){
     maxdepthleft=temp->depth;
      if(temp->depth>maxnumber){
        maxnumber=temp->data;}
      }
   }

 if(maxdepthright>maxdepthleft){
    maxdepth=maxdepthright;
  }
 else{
    maxdepth=maxdepthleft;
    }

 if(n==2){
    nodenext->constant=temp;
    startnode=nodenext;
    nodepos=temp->depth;
    nodenext->previous=temp;}

 else if(nodepos>=temp->depth){

      nodenext=startnode;
      for (int i=1;i<(temp->depth);i++){
        nodenext=nodenext->next;}

    temp->next=nodenext->constant;
    (nodenext->previous)->next=temp;
    nodenext->previous=temp;}

 else if(nodepos<temp->depth){

    node* handler = new node;
    handler->constant= temp;
    handler->previous = temp;
    nodepos = temp->depth;
      nodenext = startnode;
      for (int i=1;i<(temp->depth-1);i++){
        nodenext=nodenext->next;}
    nodenext->next = handler;}

}


int height(int v){
  head=start;
  while(true){
    if (v==head->data) {
      if(v>start->data){
        return (maxdepthright-head->depth);
      }
      else if(v<start->data){
        return (maxdepthleft-head->depth);
      }
      else{return maxdepth;}
     }
    else if(v>head->data){
      head=head->right;
    }
    else{head=head->left;}
   }
}

bool search(int num){
  head=start;
  for (int i=0;i<=maxdepth+1;i++){
    if (head->data==num){
      cout<<"The number: "<<num<<", exists in the tree."<<endl;
      return 1;
      break;
     }
    else if(num>head->data){
      if(head->right==NULL){
        cout<<"The number: "<<num<<", doesn't exists in the tree."<<endl;
        return 0;
        break;
       }
      else{head=head->right;}
     }
    else{
      if(head->left==NULL){
        cout<<"The number: "<<num<<", doesn't exists in the tree."<<endl;
        return 0;
        break;
       }
      else{head=head->left;}
     }
   }
}

void deletenode(){
  
}


void print(){
  cout<<endl;
  cout<<"/////////////////////////////////////////"<<endl;

  head=start;

  node *flag = new node;
  node *change = new node;

  while(head->data!=maxnumber){

     flag=head;
     change=head->next;

    if (head->depth==0){
      cout<<"         "<<head->data<<endl;
      if(maxnumber>head->data){
        head=head->right;}
      else{
        head=head->left;}
    }
    else if (head->data==maxnumber){
          while(flag->data!=change->data){
            cout<<"    "<<change->data;
            change = change -> next;
          }
          cout<<"    "<<change->data<<endl;

     }
    else if(maxnumber>head->data){
      while(flag->data!=change->data){
        cout<<"    "<<change->data;
        change = change -> next;
      }
      cout<<"    "<<change->data<<endl;
      head=head->right;
     }
    else{
      while(flag->data!=change->data){
        cout<<"    "<<change->data;
        change = change -> next;
      }
      cout<<"    "<<change->data<<endl;
    head=head->left;
  }

}
        flag=head;
        change=head->next;

      while(flag->data!=change->data){
        cout<<"    "<<change->data;
        change = change -> next;
      }
      cout<<"    "<<change->data<<endl;


  cout<<"/////////////////////////////////////////"<<endl;
}
int main(){
  head=start;
  int num;
  cout<<"Give data: "<<endl;
  cin>>num;
  head->data=num;
  head->depth=0;

  for(int i=0;i<=8;i++){
      cout<<"Give data: "<<endl;
      cin>>num;
      givedata(num);
  }
  print();

return 0;}
