#include <stdio.h>
#include <iostream> 
#include "block.cpp"

using namespace std;

int main (){

  Block newBlock = Block(0, 'i', 0, 0);
  newBlock.set_tag(15);
  int a = newBlock.get_tag();
  cout << a << endl;
  return 0;
  
};

