#include <stdio.h>
#include <iostream> 
#include "block.cpp"

using namespace std;

int main (){

  int datos[32]={31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0}
  Block newBlock = Block(0, 'i', 0, datos, 0);
  int a = newBlock.get_tag();
  int b = newBlock.get_valid();
  char c = newBlock.get_state();
  int d = newBlock.get_died();
  cout << "valid = " << b <<  "state = " << c <<  "died = " << d <<  "tag = " << a << endl;
  newBlock.set_tag(15);
  int a = newBlock.get_tag();
  cout << a << endl;
  return 0;
  
};

