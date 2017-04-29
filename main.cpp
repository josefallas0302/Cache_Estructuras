#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "cache_dir.h"
#include <vector>
#include "cache.h"
#include "div_dir.cpp"
 
using namespace std;

 
int main () {
	
	memory totalmemory = memory(16777256); // pow(2,24) //tamano de la direccion 24 bits 16777216
	Cache_dir L2 = Cache_dir(4096);
	Cache_L1 L1A = Cache_L1(256);

	fstream ficheroEntrada;
	string nombre ("ficheroTexto.txt");
	string frase;
	string cortado;
 
	ficheroEntrada.open ( nombre.c_str() , ios::in);
	if (ficheroEntrada.is_open()) {
		for(int i=0; i<2; i++){
		//while (! ficheroEntrada.fail()) {
			getline (ficheroEntrada,frase);
			char direccion[7];
			direccion[0]=frase[2];
			direccion[1]=frase[3];
			direccion[2]=frase[4];
			direccion[3]=frase[5];
			direccion[4]=frase[6];
			direccion[5]=frase[7];
			direccion[6]=frase[8];

			char instruccion = frase[9];
			//char direccion[frase.size()+1];//as 1 char space for null is also required
			//strcpy(direccion, frase.c_str());
			//direc.insert(direc.end(), direccion);
			cout << "Leido: " << frase << endl;
			int valor = 6;
			cortado = frase.substr(2,7);;
			if (instruccion == 'L'){
				vector <int> binario = div_dir(cortado,valor);
            			cout << " direccion: " << direccion << "instruccion: " << instruccion << "Binario: " << endl;
				for(int i = 0; i<24; i++){
					cout << binario[i] << endl;
				}
				int data = L1A.read_data_L1(binario, L2, totalmemory);
				cout << "dato: " << data << endl;
			} else {
				cout << " escribir" << endl;
			}
        	}
		ficheroEntrada.close();
	} else {
		cout << "Fichero inexistente o faltan permisos para abrirlo" << endl;  
	}







/*	vector <int> dir1 ;
	for (int i=0; i<24; i++){
		dir1.insert(dir1.end(), direc[0][i] );
	}

	vector <int> dir2 ;
	for (int i=0; i<24; i++){
		dir1.insert(dir2.end(), direc[1][i] );
	}

	vector <int> dir3 ;
	for (int i=0; i<24; i++){
		dir1.insert(dir3.end(), direc[2][i] );
	}

	vector <int> dir4 ;
	for (int i=0; i<24; i++){
		dir1.insert(dir4.end(), direc[3][i] );
	}

	L2.write_dir (dir1, 999999, totalmemory);
	L2.write_dir (dir2, 320500999, totalmemory);
	L2.write_dir (dir3, 111000111, totalmemory);

	int a = L2.read_dir(dir1, totalmemory); 
	int b = L2.read_dir(dir2, totalmemory); 
	int c = L2.read_dir(dir3, totalmemory);
	int d = L2.read_dir(dir4, totalmemory);

	cout << "data 1 = " << a <<  " data 2 = " << b <<  " data 3 = " << c <<  " data 4 = " << d << endl;

*/


//direccion main para la clase block
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

