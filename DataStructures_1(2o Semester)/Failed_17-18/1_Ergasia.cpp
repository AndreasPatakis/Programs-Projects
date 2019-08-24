#include <iostream>
using namespace std;

struct node{
  int row;
  int column;
  int number;
  node *next_column = NULL;
  node *next_row = NULL;
};

void print_list(node *list){
  node *column = new node;
  node *row = new node;
  column = list->next_column;
  while(column != NULL){
    row = column -> next_row;
    while(row != NULL){
        cout<<"COLUMN: "<<column->column<<", ROW: "<<row->row<<", NUMBER: "<<row->number<<"\n";
        row = row->next_row;
    }
    column = column->next_column;
  }
}

int main(){

//Creating root pointer;
  node *root = new node;
  node *row_conductor = new node;
  node *column_conductor = new node;
  column_conductor = root;


//Creating the list
  int current_column = 0;
  int amount_of_numbers = 7;
  int random_number;
  int row_position;
  while(amount_of_numbers > 0){
    node *column = new node;
    column_conductor->next_column = column;
    current_column += 1;
    column->column = current_column;

    for(int i = 0;i <= rand() % 2;i++){
      random_number = rand() % 101;
      row_position = rand() % 5 + 1;
      while(row_position == row_conductor->row){
        row_position = rand() % 5 + 1;
      }
      node *row = new node;
      row->number = random_number;
      row->row = row_position;
      if(i == 0){
        row_conductor = row;
      }else{
        row_conductor->next_row = row;
      }
      amount_of_numbers -= 1;
    }
    column->next_row = row_conductor;
    column_conductor = column;
  }


  //Print numbers:
    cout<<"\n";
    print_list(root);
  //  cout<<"\n"<<((root->next_column)->next_row)-> number;
}
