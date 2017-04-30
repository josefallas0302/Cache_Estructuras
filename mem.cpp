#include "mem.h"

		memory :: memory (int line) : size_line(line){
			for (int i=0; i<size_line; i++){
				l_mem.insert(l_mem.end(), 666666) ;
			}
			return;
		}

		// Busca el dato en memoria
		int memory :: find_dir (vector <int> binario){
			cout << "Entro a memoria" << endl;
			int iterator = binario.size();
			//cout << "iterador de memoria: " << iterator << endl;
			int dir_dec = 0;
			int parameter = 0;
			//for(int i = iterator-1; i>=0; i--){
			//	cout << binario[i] << endl;
			//}
			for(int i=iterator-1; i>=0; i--){
				dir_dec = dir_dec + binario[i]*pow(2,parameter);
				//cout << "suma: " << dir_dec << endl;
				parameter = parameter +1;
			} //Convierte la direccion de binario a decimal
			//cout << "Direccion en memoria: " << dir_dec << endl;
			//cout << "dato en memoria: " << l_mem[dir_dec] << endl;
			return l_mem[dir_dec];
			//Compara la direccion con cada linea de memoria y devuelve el data
		}

		// Escribe el dato a memoria
		void memory :: set_dir (vector <int> binario, int new_data){

			int iterator = binario.size();
			int dir_dec = 0;
			int parameter = 0;
			for(int i=iterator-1; i>=0; i--){
				dir_dec = dir_dec + binario[i]*pow(2,parameter);
				parameter = parameter +1;
			} //Convierte la direccion de binario a decimal

			l_mem[dir_dec] = new_data;
			 //Compara la direccion con cada linea de memoria y devuelve el data
		}

