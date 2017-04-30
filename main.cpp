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
//#include "mesi_mierda.cpp"
 
using namespace std;

 
int main () {
	
	memory totalmemory = memory(16777256); // pow(2,24) //tamano de la direccion 24 bits 16777216
	Cache_dir L2 = Cache_dir(4096);
	Cache_L1 L1A = Cache_L1(256);
	Cache_L1 L1B = Cache_L1(256);

	fstream ficheroEntrada1;
	fstream ficheroEntrada2;
	string nombre1 ("ficheroTexto1.txt");
	string nombre2 ("ficheroTexto2.txt");
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

				cout << "Leido core1: " << frase1 << endl; //imprime la linea que acaba de leer
				
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
					//read_data_L1 se encarga de saber si el dato es valido
					int data1 = L1A.read_data_L1(binario1, L2, totalmemory, L1B);
					for(int i=0; i < 2 ; i++){
						for(int j=0; j<2; j++){
							if (L1A.n_lines[index_L1].n_blocks[i].get_tag() == L1B.n_lines[index_L1].n_blocks[j].get_tag() && L1B.n_lines[index_L1].n_blocks[j].get_state() == 'M' ){
								L1A.n_lines[index_L1].n_blocks[i].set_state('S');
								L1B.n_lines[index_L1].n_blocks[i].set_state('S');
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
					cout << " escribir" << endl;

					for(int i = 0; i<2 ; i++){
						if(L1A.n_lines[index_L1].n_blocks[i].get_tag() == tag_L1){
							L1A.write_data_L1(binario1, 420420420);
							L1A.n_lines[index_L1].n_blocks[i].set_state('M');

						} else if (L1A.n_lines[index_L1].n_blocks[i].get_tag() != tag_L1 && L1A.n_lines[index_L1].n_blocks[i].get_state() == 'M'){
						//	int index_p = index_L1;
					/*		vector <int> new_binario;
							while( index_p != 0 || index_p  !=1){
								new_binario.insert( new_binario.begin(), index_p%2);
								index_p = index_p / 2;
							}
							new_binario.insert( new_binario.begin(), index_p);
							int tag_p = tag_L1;
							while( tag_p != 0 || tag_p  !=1){
								new_binario.insert( new_binario.begin(), tag_p%2);
								tag_p = tag_p / 2;
							}
							new_binario.insert( new_binario.begin(), tag_p);   */

							L2.write_dir(new_binario, L1A.n_lines[index_L1].n_blocks[i].get_data(), totalmemory);
							L1A.write_data_L1(binario1, 420420420);
							L1A.n_lines[index_L1].n_blocks[i].set_state('M');
							//L2.set_valid_dir(index_L2,0);

						}else{
						} /*

						} else if (L1A.n_lines[index_L1].n_blocks[i].get_tag() != tag_L1 && L1A.n_lines[index_L1].n_blocks[i].get_state() == 'E'){
							L1A.write_data_L1(binario1, 420420420);
							L1A.n_lines[index_L1].n_blocks[i].set_state('M');
							//L2.set_valid_dir(index_L2,0);
						} else if (L1A.n_lines[index_L1].n_blocks[i].get_tag() != tag_L1 && L1A.n_lines[index_L1].n_blocks[i].get_state() == 'S'){
							L1A.write_data_L1(binario1, 420420420);
							L1A.n_lines[index_L1].n_blocks[i].set_state('M');
						} */
					} 
				}
			}

			if (ficheroEntrada2.is_open()){
				getline (ficheroEntrada2,frase2);
				char instruccion2 = frase2[9]; //lectura o escritura

				cout << "Leido core2: " << frase2 << endl; //imprime la linea que acaba de leer
				
				cortado2 = frase2.substr(2,7); //direccion en hexa

				vector <int> binario2 = div_dir(cortado2,valor); //direccion en binario

				if (instruccion2 == 'L'){
					int data2 = L1B.read_data_L1(binario2, L2, totalmemory, L1A);
					cout << "dato: " << data2 << endl;
				} else {
					cout << " escribir" << endl;
					L1B.write_data_L1 (binario2, 420420420 );
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

