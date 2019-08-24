#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct node{
  int data;
  int depth;
  node * left=NULL;
  node * right=NULL;
  node * next=NULL;
};

 node* head=new node;
 node* start=new node;
 node* startnext= new node;
 node* nodenext= new node;

 int n=0;
 int maxdepthleft=0;
 int maxdepthright=0;
 int maxdepth=0;
 int nodepos=0;

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
        if (temp->depth==1){
            if(nodepos!=temp->depth){
                nodenext=temp;
                startnode=nodenext;
                nodepos=temp->depth;
              }else{
                temp->next=nodenext;
                nodenext=temp;
              }
            }
        else if(temp->depth>1) {
            if(nodepos!=temp->depth){
                nodenext->next=temp;
                node* nodenext=new node;
                nodenext=temp;
                nodepos=temp->depth;
              }else{
                temp->next=nodenext;
                nodenext=temp;
              }

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
      maxdepthright=temp->depth;}
    }
  else if(temp->data<head->data){
    if(temp->depth>maxdepthleft){
      maxdepthleft=temp->depth;}
    }

  if(maxdepthright>maxdepthleft){
     maxdepth=maxdepthright;
   }
  else{
     maxdepth=maxdepthleft;
     }
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

int print(){
  cout<<"/////////////////////////////////////////"<<endl;
  node *pr=new node;
  pr=start;
  cout<<pr->data<<endl;
  cout<<"    "<<depth(pr->data);
  cout<<"    "<<height(pr->data)<<endl;
  pr=pr->right;
  cout<<pr->data<<endl;
  cout<<"    "<<depth(pr->data);
  cout<<"    "<<height(pr->data)<<endl;
  pr=pr->right;
  cout<<pr->data<<endl;
  cout<<"    "<<depth(pr->data);
  cout<<"    "<<height(pr->data)<<endl;
  pr=pr->right;
  cout<<pr->data<<endl;
  cout<<"    "<<depth(pr->data);
  cout<<"    "<<height(pr->data)<<endl;
  pr=start->left;
  cout<<pr->data<<endl;
  cout<<"    "<<depth(pr->data);
  cout<<"    "<<height(pr->data)<<endl;
  pr=pr->left;
  cout<<pr->data<<endl;
  cout<<"    "<<depth(pr->data);
  cout<<"    "<<height(pr->data)<<endl;
  cout<<maxdepthleft<<endl;
  cout<<maxdepthright<<endl;
  cout<<maxdepth<<endl;
  cout<<"/////////////////////////////////////////"<<endl;
  }



int main(){
  start=head;
  int number;

  cout<<"Give number:"<<endl;
  cin>>number;
  head->data=number;
  head->depth=depth(head->data);

  n+=1;

  for(int i=0;i<=4;i++){
    cout<<"Give number:"<<endl;
    cin>>number;
    givedata(number);
    }

print();

//ssearch(40);
search(50);
    return 0;
  }
