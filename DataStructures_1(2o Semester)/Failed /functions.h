#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

int compareWords(string s1, string s2){
  if(s1 > s2){
    return 0;
  }else if(s2 > s1){
      return 1;
  }else{
      return 2;
  }
}

string* readFile(string path,int size){
  string *words = new string[size];
  int i = 0;
  ifstream file(path);
  string text_word;

  if(file.is_open()){

      while(file >> text_word && i < size){
        words[i] = text_word;
        i += 1;
      }
    file.close();
  }
  return words;
}
