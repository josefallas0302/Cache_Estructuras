#include <stdio.h>
#include <iostream> 
#include "block.cpp"

using namespace std;

int main (){

  int datos[32]={31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  Block newBlock = Block(0, 'i', 0, datos, 'N');
  int a = newBlock.get_tag();
  int b = newBlock.get_valid();
  char c = newBlock.get_state();
  char d = newBlock.get_died();
  cout << "valid = " << b <<  " state = " << c <<  " died = " << d <<  " tag = " << a << endl;
  for (int i=0; i<32; i++){
  cout << newBlock.get_data(i) << endl;
  }


  newBlock.set_tag(1500);
  newBlock.set_valid(1);
  newBlock.set_state('M');
  newBlock.set_died('V');
  int blanco[32]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  newBlock.set_data(blanco);

  int aa = newBlock.get_tag();
  int bb = newBlock.get_valid();
  char cc = newBlock.get_state();
  char dd = newBlock.get_died();
  cout << "valid = " << bb <<  " state = " << cc <<  " died = " << dd <<  " tag = " << aa << endl;
  for (int i=0; i<32; i++){
  cout << newBlock.get_data(i) << endl;
  }
  
  
  return 0;
  
};

