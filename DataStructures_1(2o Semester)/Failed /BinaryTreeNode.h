 #include <iostream>
#include <string>
#include "functions.h"
#include <queue>

using namespace std;

struct node{
  string word_english;
  string word_greek;
  node *right_child = NULL;
  node *left_child = NULL;
};

node* BinaryTreeNode_set(string english_word, string greek_word){
    node *leaf = new node;
    leaf->word_english = english_word;
    leaf->word_greek = greek_word;
    leaf->left_child = NULL;
    leaf->right_child = NULL;
    return leaf;
}

void BinaryTreeNode_create(node *root, node *leaf){
    int state;
    node *t = new node;
    t = root;
    while(t != NULL){
        state = compareWords(t->word_english,leaf->word_english);
        if (state == 0){
            if(t->left_child == NULL){
              t->left_child = leaf;
              break;
            }
            t = t->left_child;
        }else if( state == 1){
            if(t->right_child == NULL){
              t->right_child = leaf;
              break;
            }
            t = t->right_child;
        }else{
          cout<<"Word already exists.\n";
          break;
        }
    }
}

//Αποσταση 2 κομβων
int nodes_distance(node* root,node *leaf){
  int height = 1;
  int state;
  node *temp_node = new node;
  temp_node = root;
  while(temp_node != NULL){
    state = compareWords(temp_node->word_english,leaf->word_english);
    if(state == 0){
      temp_node = temp_node->left_child;
      height += 1;
    }else if(state == 1){
      temp_node = temp_node->right_child;
      height += 1;
    }else{
      return height;
    }
  }
  return 0;
}

//Υπολογισμος ύψους δενδρου
  int tree_height(node *leaf){
    int height = 1;
    bool has_child;
    queue<node*> q;
    node *temp_node = new node;
    temp_node = leaf;
    while(temp_node){
      has_child = false;
      if(temp_node->left_child){
        q.push(temp_node->left_child);
        has_child = true;
      }
      if(temp_node->right_child){
        q.push(temp_node->right_child);
        has_child = true;
      }
      if(has_child){
        height += 1;
      }
      if(q.front() == NULL){
        break;
      }else{
        temp_node = q.front();
        q.pop();
      }
    }
    height = nodes_distance(leaf,temp_node);
    return height;
  }

  int total_nodes(node *root){
    queue<node*> q;
    node *temp_node = new node;
    int nodes = 1;
    temp_node = root;
    while(temp_node){
      if(temp_node->left_child){
        q.push(temp_node->left_child);
      }
      if(temp_node->right_child){
        q.push(temp_node->right_child);
      }
      temp_node = q.front();
      if(temp_node){
        nodes += 1;
      }
      q.pop();
    }
    return nodes;
  }



//Δημιουργια ουρας και εκτυπωση δενδρου
  void BinaryTreeNode_print(node *root){
    int total_height = tree_height(root);
    int current_height;
    int leaf_height;
    queue<node*> q;
    node *temp_node = new node;
    temp_node = root;
    current_height = 1;
    while(temp_node){
      cout<<temp_node->word_english.at(0)<<" ";

      if(temp_node->left_child){
        q.push(temp_node->left_child);
      }
      if(temp_node->right_child){
        q.push(temp_node->right_child);
      }
      temp_node = q.front();
      if(!temp_node){
        break;
      }
      leaf_height = nodes_distance(root,temp_node);
      //cout<<"Word: "<<temp_node->word_english<<" | Current: "<<current_height<<" | Leaf: "<<leaf_height<<endl;
      if(current_height != leaf_height){
        cout<<endl;
        current_height = leaf_height;
      }
      q.pop();
    }
  }
