#include <iostream>
#include <ctime>
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

void print_matrix(node *list){
  node *column = new node;
  node *row = new node;
  bool notNull = true;
  column = list->next_column;

  for(int i=1;i<=5;i++){
    row = column->next_row;
    for(int j=1;j<=5;j++){
      if(notNull && row->row == j){
        cout<<row->number<<" ";
        if(row->next_row != NULL){
            row = row->next_row;
        }
      }else{
        cout<<"0 ";
      }
    }
    if(column->column +1 == i+1){
      if(column->next_column == NULL){
        notNull = false;
      }else{
        column = column->next_column;
      }
    }
    cout<<endl;
  }
}

void create_list(node *root){
  node *row_conductor = new node;
  node *column_conductor = new node;
  int current_column;
  int amount_of_numbers;
  int random_number;
  int row_position;
  column_conductor = root;
  current_column = 0;
  amount_of_numbers = 7;
  random_number = 0;
  row_position = 0;

 while(amount_of_numbers > 0){
   node *column = new node;
   column_conductor->next_column = column;
   current_column += 1;
   column->column = current_column;

   for(int i = 0;i <= rand() % 2;i++){
     random_number = rand() % 101;
     row_position = rand()% 5 + 1;
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
   //Sort by row_position
   if(row_conductor->next_row != NULL){
     if(row_conductor->row > (row_conductor->next_row)->row){
       node *temp = new node;
       temp = row_conductor;
       row_conductor = row_conductor->next_row;
       row_conductor->next_row = temp;
       (row_conductor->next_row)->next_row = NULL;
     }
   }
   //End of sort
   column->next_row = row_conductor;
   column_conductor = column;
  }
}



 node *copy_matrix(node *root){
   node *new_matrix = new node;
   bool first;
   //nodes for searching the given list(root)
   node *root_row = new node;
   node *root_column = new node;
   //actual new nodes of new_matrix
   node *new_row;
   node *new_column;
   //a temp node for new_matrix
   node* temp_row = new node;
   node* temp_column = new node;
   //giving root_column the first column node
   root_column = root->next_column;
   temp_column = new_matrix;

   while(root_column != NULL){
     new_column = new node;
     first = true;
     //coping column data
     new_column->column = root_column->column;
     root_row = root_column->next_row;
     while(root_row != NULL){
       new_row = new node;
       new_row ->row = root_row-> row;
       new_row ->number = root_row->number;
       if(first){
         new_column->next_row = new_row;
         temp_row = new_row;
         first = false;
       }else{
         temp_row->next_row = new_row;
         temp_row = new_row;
       }
       root_row = root_row->next_row;
     }
     temp_column->next_column = new_column;
     temp_column = temp_column->next_column;
     root_column = root_column->next_column;
   }
   return new_matrix;
 }




void matrix_addition(node **root){
  cout<<root[101];
}

int main(){

//Creating array to store roots, declaring srand()

  node *root[2];
  srand(time(NULL));

  cout<<sizeof(root)/sizeof(root[0]);
//Creating the list
  for(int i = 0;i<2;i++){
    node *root_pointer = new node;
    root[i] = root_pointer;
    create_list(root[i]);
  }



  //Print numbers:

  for(int i=0;i<2;i++){
    //cout<<"LIST: "<<i+1<<endl;
    //print_list(root[i]);
    //cout<<endl;
    cout<<"MATRIX: "<<i+1<<endl;
    print_matrix(root[i]);
    cout<<endl;

  }
  matrix_addition(root);
}
