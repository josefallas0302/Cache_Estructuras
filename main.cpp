#include <stdio.h>
#include <iostream> 
#include "cache_dir.cpp"
//#define "cache_dir.cpp"
#include <vector>
//#include "mem.cpp"
//#include "line.cpp"
//#define "line.cpp"
#include "block.h"

using namespace std;

int main (){

	memory totalmemory = memory(1000); // pow(2,24) //tamano de la direccion 24 bits 16777216
	Cache_dir L2 = Cache_dir(4096);

	vector <int> dir1 ;
	for (int i=0; i<20; i++){
		dir1.insert(dir1.end(), 0 );
	}
	for (int i=0; i<4; i++){
		dir1.insert(dir1.end(), 1 );
	}

	vector <int> dir2 ;
	for (int i=0; i<18; i++){
		dir2.insert(dir2.end(), 0 );
	}
	for (int i=0; i<6; i++){
		dir2.insert(dir2.end(), 1 );
	}

	vector <int> dir3 ;
	for (int i=0; i<22; i++){
		dir3.insert(dir3.end(), 0 );
	}
	for (int i=0; i<2; i++){
		dir3.insert(dir3.end(), 1 );
	}

	vector <int> dir4 ;
	for (int i=0; i<16; i++){
		dir4.insert(dir4.end(), 0 );
	}
	for (int i=0; i<8; i++){
		dir4.insert(dir4.end(), 1 );
	}


	L2.write_dir (dir1, 999999, totalmemory);
	L2.write_dir (dir2, 320500999, totalmemory);
	L2.write_dir (dir3, 111000111, totalmemory);

	int a = L2.read_dir(dir1, totalmemory); 
	int b = L2.read_dir(dir2, totalmemory); 
	int c = L2.read_dir(dir3, totalmemory);
	int d = L2.read_dir(dir4, totalmemory);

	cout << "data 1 = " << a <<  " data 2 = " << b <<  " data 3 = " << c <<  " data 4 = " << d << endl;




//Prueba main para la clase block
/*
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
 */ 
 
  return 0;
  
};

