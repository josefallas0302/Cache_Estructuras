#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "cache_dir.h"
#include <vector>
#include "line.h"
#include "block.h"
#include "cache.h"
#include "div_dir.cpp"

 
using namespace std;

 
int main () {
	
	memory totalmemory = memory(16777256); // pow(2,24) //tamano de la direccion 24 bits 16777216
	Cache_dir L2 = Cache_dir(4096);
	Cache_L1 L1A = Cache_L1(256);
	Cache_L1 L1B = Cache_L1(256);

	fstream ficheroEntrada1;
	fstream ficheroEntrada2;
	string nombre1 ("ficheroTexto5.txt");
	string nombre2 ("ficheroTexto6.txt");
	string frase1;
	string frase2;
	string cortado1;
	string cortado2;

	int valor = 6; //tamano de la direccion
 
	ficheroEntrada1.open ( nombre1.c_str() , ios::in);
	ficheroEntrada2.open ( nombre2.c_str() , ios::in);
	if (ficheroEntrada1.is_open()) {
		for(int i=0; i<2; i++){
			for( int core1=0; core1<3; core1++){
				getline (ficheroEntrada1,frase1);
				char instruccion1 = frase1[9]; //lectura o escritura

				cout << "" << endl;
				cout << "--------- Nueva Instruccion --------" << endl;
				cout << "Instruccion leida por Core1: " << frase1 << endl; //imprime la linea que acaba de leer
				
				cortado1 = frase1.substr(2,7); //direccion en hexa

				vector <int> binario1 = div_dir(cortado1,valor); //direccion en binario

				//Imprime la direccion en binario para revisar que este correcta
		    		//cout << " direccion: " << cortado1 << "instruccion: " << instruccion1 << "Binario: " << endl;
				//for(int i = 0; i<24; i++){
				//	cout << binario1[i] << endl;
				//}

			int iterator = binario1.size(); //Tamano de la direccion de binario
			int index_L2 = 0;
			int parameter1 = 0;
			for(int i=iterator-1; i>iterator-13; i--){
				index_L2 = index_L2 + binario1[i]*pow(2,parameter1);
				parameter1 = parameter1 + 1;
			} // Convierte el index de binario a decimal (para L2)
		
			int tag_L1 = 0;  	// TAG L1
			int index_L1 = 0;	// IndexL1
			int parameter = 0;			
			for(int i=0; i<8; i++){
				index_L1 = index_L1 + binario1[i]*pow(2,parameter);
				parameter = parameter + 1;
			} // Convierte el index de binario a decimal (para L1)
				
			parameter = 0;
			for(int i=8; i<iterator; i++){
				tag_L1 = tag_L1 + binario1[i]*pow(2,parameter);
				parameter = parameter + 1;
			} // Convierte el tag de binario a decimal (para L1)

			//PARA COMPROBAR RESULTADOS
			// cout << "index L2: " << index_L2 << "index L1: " << index_L1 << "tag L1: " << tag_L1 << endl;
 
//------------------------------------------------------------------------------------------------------------------------------

				if (instruccion1 == 'L'){
					cout << "Lectura" << endl;
					//read_data_L1 se encarga de saber si el dato es valido
					int data1 = L1A.read_data_L1(binario1, L2, totalmemory, L1B);
					for(int i=0; i < 2 ; i++){


						for(int j=0; j<2; j++){
							if (L1A.n_lines[index_L1].n_blocks[i].get_tag() == L1B.n_lines[index_L1].n_blocks[j].get_tag() && L1B.n_lines[index_L1].n_blocks[j].get_state() == 'M' ){

								L1A.n_lines[index_L1].n_blocks[i].set_state('S');
								L1B.n_lines[index_L1].n_blocks[j].set_state('S');
								L2.write_dir(binario1, data1, totalmemory);	

							}else if(L1A.n_lines[index_L1].n_blocks[i].get_tag() == L1B.n_lines[index_L1].n_blocks[j].get_tag() && L1B.n_lines[index_L1].n_blocks[j].get_state() == 'E'){ 


								L1A.n_lines[index_L1].n_blocks[i].set_state('S');
								L1B.n_lines[index_L1].n_blocks[i].set_state('S');

							} else if(L1A.n_lines[index_L1].n_blocks[j].get_state() == 'M'){
								L1A.n_lines[index_L1].n_blocks[i].set_state('M');
							} else {
								L1A.n_lines[index_L1].n_blocks[i].set_state('E');
							}
						}
					}	
					cout << "dato: " << data1 << endl;

				} else {
					cout << " Escritura " << endl;

					int old_data0 = L1A.n_lines[index_L1].n_blocks[0].get_data();
					int old_data1 = L1A.n_lines[index_L1].n_blocks[1].get_data();
					int old_tag0 = L1A.n_lines[index_L1].n_blocks[0].get_tag();
					int old_tag1 = L1A.n_lines[index_L1].n_blocks[1].get_tag();
					char old_state0 = L1A.n_lines[index_L1].n_blocks[0].get_state();
					char old_state1 = L1A.n_lines[index_L1].n_blocks[1].get_state();

					L1A.write_data_L1(binario1, 420420420, L1B, L2, totalmemory);

					if(L1A.n_lines[index_L1].n_blocks[0].get_tag() == tag_L1){
						L1A.n_lines[index_L1].n_blocks[0].set_state('M');
						if(old_tag0 != tag_L1 && old_state0 == 'M'){
							vector <int> new_dir = generate_binario(old_tag0, index_L1);
							L2.write_dir (new_dir, old_data0, totalmemory);
						}
					} else {
						L1A.n_lines[index_L1].n_blocks[1].set_state('M');
						if(old_tag1 != tag_L1 && old_state1 == 'M'){
							vector <int> new_dir = generate_binario(old_tag1, index_L1);
							L2.write_dir (new_dir, old_data1, totalmemory);
						}
					}
				}
			}

			if (ficheroEntrada2.is_open()){
				getline (ficheroEntrada2,frase2);
				char instruccion2 = frase2[9]; //lectura o escritura

				cout << "" << endl;
				cout << "--------- Nueva Instruccion --------" << endl;
				cout << "Instruccion leida por Core2: " << frase2 << endl; //imprime la linea que acaba de leer
				
				cortado2 = frase2.substr(2,7); //direccion en hexa

				vector <int> binario2 = div_dir(cortado2,valor); //direccion en binario

				//Imprime la direccion en binario para revisar que este correcta
		    		//cout << " direccion: " << cortado1 << "instruccion: " << instruccion1 << "Binario: " << endl;
				//for(int i = 0; i<24; i++){
				//	cout << binario1[i] << endl;
				//}

				int iterator2 = binario2.size(); //Tamano de la direccion de binario
				int index2_L2 = 0;
				int parameter2 = 0;
				for(int i=iterator2-1; i>iterator2-13; i--){
					index2_L2 = index2_L2 + binario2[i]*pow(2,parameter2);
					parameter2 = parameter2 + 1;
				} // Convierte el index de binario a decimal (para L2)
		
				int tag2_L1 = 0;  	// TAG L1
				int index2_L1 = 0;	// IndexL1
				int parameter22 = 0;			
				for(int i=0; i<8; i++){
					index2_L1 = index2_L1 + binario2[i]*pow(2,parameter22);
					parameter22 = parameter22 + 1;
				} // Convierte el index de binario a decimal (para L1)
				
				parameter22 = 0;
				for(int i=8; i<iterator2; i++){
					tag2_L1 = tag2_L1 + binario2[i]*pow(2,parameter22);
					parameter22 = parameter22 + 1;
				} // Convierte el tag de binario a decimal (para L1)

				//PARA COMPROBAR RESULTADOS
				// cout << "index L2: " << index_L2 << "index L1: " << index_L1 << "tag L1: " << tag_L1 << endl;
 
//------------------------------------------------------------------------------------------------------------------------------

				if (instruccion2 == 'L'){
					cout << "Lectura" << endl;
					//read_data_L1 se encarga de saber si el dato es valido
					int data2 = L1B.read_data_L1(binario2, L2, totalmemory, L1A);
					for(int i=0; i < 2 ; i++){
						for(int j=0; j<2; j++){
							if (L1B.n_lines[index2_L1].n_blocks[i].get_tag() == L1A.n_lines[index2_L1].n_blocks[j].get_tag() && L1A.n_lines[index2_L1].n_blocks[j].get_state() == 'M' ){

								L1B.n_lines[index2_L1].n_blocks[i].set_state('S');
								L1A.n_lines[index2_L1].n_blocks[j].set_state('S');
								L2.write_dir(binario2, data2, totalmemory);	

							}else if(L1B.n_lines[index2_L1].n_blocks[i].get_tag() == L1A.n_lines[index2_L1].n_blocks[j].get_tag() && L1A.n_lines[index2_L1].n_blocks[j].get_state() == 'E'){ 


								L1B.n_lines[index2_L1].n_blocks[i].set_state('S');
								L1A.n_lines[index2_L1].n_blocks[i].set_state('S');

							} else if(L1B.n_lines[index2_L1].n_blocks[j].get_state() == 'M'){
								L1B.n_lines[index2_L1].n_blocks[i].set_state('M');
							} else {
								L1B.n_lines[index2_L1].n_blocks[i].set_state('E');
							}
						}
					}	
					cout << "dato: " << data2 << endl;

				} else {
					cout << " Escritura " << endl;

					int old_data02 = L1B.n_lines[index2_L1].n_blocks[0].get_data();
					int old_data12 = L1B.n_lines[index2_L1].n_blocks[1].get_data();
					int old_tag02 = L1B.n_lines[index2_L1].n_blocks[0].get_tag();
					int old_tag12 = L1B.n_lines[index2_L1].n_blocks[1].get_tag();
					char old_state02 = L1B.n_lines[index2_L1].n_blocks[0].get_state();
					char old_state12 = L1B.n_lines[index2_L1].n_blocks[1].get_state();
		
					L1B.write_data_L1(binario2, 123456789, L1A, L2, totalmemory);

					if(L1B.n_lines[index2_L1].n_blocks[0].get_tag() == tag2_L1){
						L1B.n_lines[index2_L1].n_blocks[0].set_state('M');
						if(old_tag02 != tag2_L1 && old_state02 == 'M'){
							vector <int> new_dir2 = generate_binario(old_tag02, index2_L1);
							L2.write_dir (new_dir2, old_data02, totalmemory);
						}
					} else {
						L1B.n_lines[index2_L1].n_blocks[1].set_state('M');
						if(old_tag12 != tag2_L1 && old_state12 == 'M'){
							vector <int> new_dir2 = generate_binario(old_tag12, index2_L1);
							L2.write_dir (new_dir2, old_data12, totalmemory);
						}
					}
				}

			} else {
				cout << "Fichero inexistente o faltan permisos para abrirlo" << endl; 
			} 

        	}
		ficheroEntrada2.close();
		ficheroEntrada1.close();
	} else {
		cout << "Fichero inexistente o faltan permisos para abrirlo" << endl;  
	}
 
  return 0;
  
};

