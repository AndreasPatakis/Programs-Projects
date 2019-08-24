#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct node{
  int data;
  int depth;
  int greater;
  int lower;
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
node* list = new node;
node* startlist = new node;


int n = 1;
int maxdepthleft = 0;
int maxdepthright = 0;
int maxdepth = 0;
int nodepos = 0;
int maxnumber = 0;
int noflist = 0;


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


int createlist(int k){
  node* handler = new node;
  int root=start->data;
  int numberflag;

bool f=true;

    if(k==root){

        noflist += 1;
        list->data = start->data;
        startlist = list;
        nodenext = startnode;



      while(nodenext != NULL){

          numberflag = (nodenext->constant)->data;
          handler = (nodenext->constant)->next;

            while(handler->data != numberflag){

                  if(list->next==NULL){
                    node* create = new node;
                    list->next = create;
                    list = list->next;}
                  else{list = list->next;}

                  noflist += 1;
                  list->data = handler->data;
                  handler = handler->next;}

                if(list->next==NULL){
                  node* create = new node;
                  list->next = create;
                  list = list->next;}
                else{list = list->next;}

                  noflist += 1;
                  list->data = handler->data;
                  nodenext = nodenext->next;
               }
      }else if(k<root){
        handler = start;
        while (handler->data != k){
            if (k>handler->data){
              handler = handler->right;}
            else{handler = handler->left;}
          }

          noflist += 1;
          list->data = handler->data;
          startlist = list;
          nodenext = startnode;
          for(int i=1;i<=(handler->depth);i++){
            nodenext = nodenext->next;}


            while(nodenext != NULL){

                numberflag = (nodenext->constant)->data;
                handler = (nodenext->constant)->next;

                  while(handler->data != numberflag){

                    if(handler->data < root){
                        if(list->next==NULL){
                          node* create = new node;
                          list->next = create;
                          list = list->next;}
                        else{list = list->next;}

                        noflist += 1;
                        list->data = handler->data;
                        handler = handler->next;}
                    else{handler = handler->next;}
                  }

                    if(handler->data < root){
                      if(list->next==NULL){
                        node* create = new node;
                        list->next = create;
                        list = list->next;}
                      else{list = list->next;}

                        noflist += 1;
                        list->data = handler->data;}
                        nodenext = nodenext->next;
                     }
              }else{
                handler = start;
                while (handler->data != k){
                    if (k>handler->data){
                      handler = handler->right;}
                    else{handler = handler->left;}
                  }

                  noflist += 1;
                  list->data = handler->data;
                  startlist = list;
                  nodenext = startnode;
                  for(int i=1;i<=(handler->depth);i++){
                    nodenext = nodenext->next;}


                    while(nodenext != NULL){

                        numberflag = (nodenext->constant)->data;
                        handler = (nodenext->constant)->next;

                          while(handler->data != numberflag){

                            if(handler->data > root){
                                if(list->next==NULL){
                                  node* create = new node;
                                  list->next = create;
                                  list = list->next;}
                                else{list = list->next;}

                                noflist += 1;
                                list->data = handler->data;
                                handler = handler->next;}
                            else{handler = handler->next;}
                          }

                            if(handler->data > root){
                              if(list->next==NULL){
                                node* create = new node;
                                list->next = create;
                                list = list->next;}
                              else{list = list->next;}

                                noflist += 1;
                                list->data = handler->data;}
                                nodenext = nodenext->next;
                             }
                }
        list->next=startlist;
  }

int rate(){
  node* savenext = new node;
  node* handler = new node;
  node* ratingnumber = new node;
  int greatnumber=8;
  int deletedata;
  int minumber;
  int beginninglist;
  bool f;


  while(noflist > 2){
    cout<<" "<<endl;
    cout<<"~~~~~~ARITHMOS : "<<noflist<<"~~~~~~"<<endl;
    minumber = n;
    list = startlist;
    ratingnumber = list;
    handler = list->next;
    beginninglist = startlist->data;
    f = true;

  while(f and handler->data!=beginninglist){


    ratingnumber->greater = 0;
    ratingnumber->lower = 0;

    cout<<ratingnumber->data<<endl;

    if(handler->data < greatnumber){
      while(ratingnumber->data != handler->data){
          if(ratingnumber->data < handler->data){
              ratingnumber->greater += 1;}
          else{ratingnumber->lower += 1;}
      handler = handler->next;}
      if ((ratingnumber->greater - ratingnumber->lower) == 0){
        list = ratingnumber;
        cout<<"EFTASE 0: "<<ratingnumber->data<<endl;
        f=false;
        }
      else if (abs(ratingnumber->greater - ratingnumber->lower) < minumber){
        minumber = abs(ratingnumber->greater - ratingnumber->lower);}


      cout<<"MEGALUTEROI : "<<ratingnumber->greater<<" - MIKROTEROI : "<<ratingnumber->lower<<endl;
    }else{handler = handler->next;}
 if(f){
    ratingnumber = ratingnumber->next;
    handler = ratingnumber->next;}
  }

if(f){
    ratingnumber->greater = 0;
    ratingnumber->lower = 0;

    cout<<ratingnumber->data<<endl;

  if(handler->data < greatnumber){
    while(ratingnumber->data != handler->data){
        if(ratingnumber->data < handler->data){
            ratingnumber->greater += 1;}
            else{ratingnumber->lower += 1;}
            handler = handler->next;}
            if ((handler->greater - handler->lower) == 0){
              cout<<"EFTASE 0: "<<handler->data<<endl;
              minumber = 0;
              f=false;
            }
            else if (abs(ratingnumber->greater - ratingnumber->lower) < minumber){
              minumber = abs(ratingnumber->greater - ratingnumber->lower);}

              cout<<"MEGALUTEROI : "<<ratingnumber->greater<<" - MIKROTEROI : "<<ratingnumber->lower<<endl;}
  }else{handler = handler->next;}

  if (f){
    int difference;
    list = startlist;

    while (f){
      if(list->data < greatnumber){
        difference = list->greater - list->lower;
        if (difference==minumber or difference==minumber*(-1)){
            cout<<"O ARITHMOS EINAI O: "<<list->data<<endl;f=false;}
        else{list = list->next;}
      }else{list = list->next;}
      }
   }
   cout<<"DIAGRAFH : "<<list->data<<endl;
   deletedata = list->data;
   list= startlist;
   while((list->next)->data != deletedata){list = list->next;}
     savenext = list->next;
     list->next = (list->next)->next;
     delete savenext;
     noflist -= 1;
     startlist = list;

  }
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

change = startlist;
cout<<"List: ";
while((change->next)->data!=startlist->data){
  cout<<change->data<<" , ";
  change = change->next;
}cout<<list->data<<endl;

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
  createlist(8);
  print();
  rate();


return 0;}
