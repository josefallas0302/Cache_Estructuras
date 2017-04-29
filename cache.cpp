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


	void Cache_L1::write_data_L1 (char hexa, int dato){
			vector <int> binario = div_dir(hexa, 6);
			int iterator = binario.size();
			int tag = 0;  // TAG es lo importante Aquí
			int index = 0;	// Index es lo importante aquí


			int parameter = 0;			
			
			for(int i=0; i<8; i++){
				index = tag + binario[i]*pow(2,parameter);
				parameter = parameter + 1;
			}

			
			parameter = 0;

			for(int i=8; i<iterator; i++){
				tag = tag + binario[i]*pow(2,parameter);
				parameter = parameter + 1;
			}

			n_lines[index].write_in_line(dato, tag);
			
		}
	
	void Cache_L1::Load_from_mem(char hexa, Cache_dir L2, memory memoria ){
			vector <int> memory_direction = div_dir(hexa, 6);
			int dato = L2.read_dir(memory_direction, memoria);
			this->write_data_L1(memory_direction, dato);
		
		}

	int Cache_L1::read_data_L1 (char hexa){
			int dato;
			vector <int> binario = div_dir(hexa, 6);
			int iterator = binario.size();
			int tag = 0;  // TAG es lo importante Aquí
			int index = 0;	// Index es lo importante aquí


			int parameter = 0;			
			
			for(int i=0; i<8; i++){
				index = tag + binario[i]*pow(2,parameter);
				parameter = parameter + 1;
			}

			
			parameter = 0;

			for(int i=8; i<iterator; i++){
				tag = tag + binario[i]*pow(2,parameter);
				parameter = parameter + 1;
			}
			
			
			dato = n_lines[index].read_in_line(tag);
			
			if(dato == -1){
				this->Load_from_mem(vector <int> memory_direction);							
			}
			else{
					return dato;
			}
	
		}
