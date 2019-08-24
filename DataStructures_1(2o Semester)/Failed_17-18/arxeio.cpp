#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main(){

fstream file;
file.open("t102.txt");
string line;

int p=0;
while(!file.eof()) {
  getline(file,line);
  istringstream iss(line);
  string word;
  if (p==4){
    //cout<<line<<endl;
    file.ignore(1);}
    else{
  for(int i=0;i<21;i++){
      iss >> word;
      if (i!=4&&i!=20){
      cout << word<<" ";}
    }
  }
p+=1;

    cout<<endl;
   }
 return 0;
}
