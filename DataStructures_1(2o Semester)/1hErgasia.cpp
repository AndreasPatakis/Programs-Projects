#include <iostream>

using namespace std;

struct node{
  int row;
  int column;
  int element;
  node *next_row = NULL;
  node *next_column = NULL;
}

struct elements_data{
  int row;
  int column;
  int element;
  elements_data *next = NULL;
}

int elements_list(n){
  int row;
  int column;
  for(int i;i<n;i++){
    elements_data *temp = new elements_data;
    temp->row = rand() % n;
    temp->column = rand() % n;
    temp-> element = rand() % 200;
  }
}

int main(){
  int n = -1;

  while(n<=0){
    cout<<"Give an integer for the size of matrix.\nMust be greater than zero.\n";
    cin>>n;
  }

  for(int i=0;i<n;i++){
    cout<<rand()%100<<"\n";

  }

}
