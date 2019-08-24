#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
//#include "functions.h"
#include "BinaryTreeNode.h"


using namespace std;

int main(){
  //Διαβαζουμε απο ενα αρχειο size λεξεις
  int size = 10;
  string *greek_words;
  string *english_words;

  english_words = readFile("english_words.txt",size);
  greek_words = readFile("greek_words.txt",size);

  //Ριζα του δενδρου
  node *root = new node;
  node *leaf = new node;
  //Δημιουργεια δενδρου
  for(int i = 0; i<size; i++){
    leaf = BinaryTreeNode_set(english_words[i],greek_words[i]);
    BinaryTreeNode_create(root,leaf);
  }
  //Εκτυπωση ουρας
  BinaryTreeNode_print(root->right_child);

  return 0;
}
