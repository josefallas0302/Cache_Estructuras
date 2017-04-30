/*#include <stdio.h>
#include <iostream> 
#include <vector>
#include <math.h>*/

#include "cache.h"
	

	Cache_L1::Cache_L1 (int numero_lineas){
				for (int i = 0; i < numero_lineas; i++ ){
					n_lines.push_back(Line(2));

		}
	
	}


	void Cache_L1::write_data_L1 (vector <int> memory_direction, int dato){
			vector <int> binario = memory_direction;
			int iterator = binario.size(); //Tamano de la direccion en binario
			int index = 0;
			int parameter1 = 0;
			for(int i=iterator-1; i>iterator-9; i--){
				index = index + binario[i]*pow(2,parameter1);
				parameter1 = parameter1 + 1;
			} // Convierte el index de binario a decimal (12 bits para el index)

			int tag = 0;
			int parameter2 = 0;
			for(int i=iterator-9; i>=0; i--){
				tag = tag + binario[i]*pow(2,parameter2);
				parameter2 = parameter2 + 1;
			} //Convierte el tag de binario a decimal (iterator-index = bits de tag)

			//cout << "index: " << index << " tag: " << tag << endl;
			n_lines[index].write_in_line(dato, tag);
			
		}
	
	int Cache_L1::Load_from_mem(vector <int> memory_direction, Cache_dir L2, memory memoria ){
			int dato = L2.read_dir(memory_direction, memoria);
			cout << "dato en cache L1: " << dato << endl;
			this->write_data_L1(memory_direction, dato);
			return dato;
		}

	int Cache_L1::read_data_L1 (vector <int> memory_direction, Cache_dir L2, memory memoria, Cache_L1 L1B){
			int dato;

			vector <int> binario = memory_direction;
			int iterator = binario.size(); //Tamano de la direccion en binario
			int index = 0;
			int parameter1 = 0;
			for(int i=iterator-1; i>iterator-9; i--){
				index = index + binario[i]*pow(2,parameter1);
				parameter1 = parameter1 + 1;
			} // Convierte el index de binario a decimal (12 bits para el index)

			int tag = 0;
			int parameter2 = 0;
			for(int i=iterator-9; i>=0; i--){
				tag = tag + binario[i]*pow(2,parameter2);
				parameter2 = parameter2 + 1;
			} //Convierte el tag de binario a decimal (iterator-index = bits de tag)

			//cout << "index: " << index << " tag: " << tag << endl;
		
			dato = n_lines[index].read_in_line(tag);
			
			if(dato == -1){
				cout << "Buscando dato en el otro cache" << endl;
				int dato2 = L1B.n_lines[index].read_in_line(tag);
					if(dato2 == -1){
						cout << "cargando de L2" << endl;
						int data = this->Load_from_mem(memory_direction, L2, memoria);
						return data;
					} else {
						return dato2;
					}						
			} else {
				return dato;
			}
	
		}

	Line Cache_L1::get_line(int index){
			Line linea = n_lines[index];
			return linea;
		}
