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


	void Cache_L1::write_data_L1 (vector <int> memory_direction, int dato, Cache_L1 L1B, Cache_dir L2, memory totalmemory){
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
			

			int old_data0 = this->n_lines[index].n_blocks[0].get_data();
			int old_data1 = L1B.n_lines[index].n_blocks[1].get_data();
			int old_tag0 = this->n_lines[index].n_blocks[0].get_tag();
			int old_tag1 = L1B.n_lines[index].n_blocks[1].get_tag();
			char old_state0 = L1B.n_lines[index].n_blocks[0].get_state();
			char old_state1 = L1B.n_lines[index].n_blocks[1].get_state();
		
			this->n_lines[index].write_in_line(dato, tag);

			if(this->n_lines[index].n_blocks[0].get_tag() == tag){
				this->n_lines[index].n_blocks[0].set_state('M');
				if(old_tag0 != tag && old_state0 == 'M'){
					vector <int> new_dir2 = generate_binario(old_tag0, index);
					L2.write_dir (new_dir2, old_data0, totalmemory);
				}
			} else {
				this->n_lines[index].n_blocks[1].set_state('M');
				if(old_tag1 != tag && old_state1 == 'M'){
					vector <int> new_dir2 = generate_binario(old_tag1, index);
					L2.write_dir (new_dir2, old_data1, totalmemory);
				}
			}



			//this->n_lines[index].n_blocks[0].set_state('M');
			//this->n_lines[index].n_blocks[1].set_state('M');
			
			cout << "" << endl;
			cout << " Lineas de los caches L1 despues de la escritura " << endl;
			cout << " L1A bloque 1" << endl;
			this->n_lines[index].n_blocks[1].block_info();
			cout << " L1A bloque 0" << endl;
			this->n_lines[index].n_blocks[0].block_info();
			cout << " L1B bloque 0" << endl;
			L1B.n_lines[index].n_blocks[0].block_info();
			cout << " L1B bloque 1" << endl;
			L1B.n_lines[index].n_blocks[1].block_info();
			cout << "" << endl;

		}
	
	int Cache_L1::Load_from_mem(vector <int> memory_direction, Cache_dir L2, memory memoria, Cache_L1 L1B ){
			int dato = L2.read_dir(memory_direction, memoria);
			cout << "dato en cache L1: " << dato << endl;
			this->write_data_L1(memory_direction, dato, L1B, L2, memoria);

			return dato;
		}

	int Cache_L1::read_data_L1 (vector <int> memory_direction, Cache_dir L2, memory memoria, Cache_L1 L1B){

			int lectura = 1;
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

				cout << "" << endl;
				cout << " Lineas de los caches L1 antes de la lectura " << endl;
				cout << " L1A bloque 1" << endl;
				this->n_lines[index].n_blocks[1].block_info();
				cout << " L1A bloque 0" << endl;
				this->n_lines[index].n_blocks[0].block_info();
				cout << " L1B bloque 0" << endl;
				L1B.n_lines[index].n_blocks[0].block_info();
				cout << " L1B bloque 1" << endl;
				L1B.n_lines[index].n_blocks[1].block_info();
				cout << "" << endl;

			dato = n_lines[index].read_in_line(tag);
			
			if(dato == -1){
				cout << "Buscando dato en el otro cache" << endl;
				int dato2 = L1B.n_lines[index].read_in_line(tag);
					if(dato2 == -1){
						cout << "cargando de L2" << endl;
						int data = this->Load_from_mem(memory_direction, L2, memoria, L1B);
						
						this->n_lines[index].n_blocks[1].block_info();
						cout << "" << endl;
						cout << " Lineas de los caches L1 despues de la lectura " << endl;
						cout << " L1A bloque 1" << endl;
						this->n_lines[index].n_blocks[1].block_info();
						cout << " L1A bloque 0" << endl;
						this->n_lines[index].n_blocks[0].block_info();
						cout << " L1B bloque 0" << endl;
						L1B.n_lines[index].n_blocks[0].block_info();
						cout << " L1B bloque 1" << endl;
						L1B.n_lines[index].n_blocks[1].block_info();
						cout << "" << endl;
						return data;
					} else {
						cout << "" << endl;
						cout << " Lineas de los caches L1 despues de la lectura " << endl;
						cout << " L1A bloque 1" << endl;
						this->n_lines[index].n_blocks[1].block_info();
						cout << " L1A bloque 0" << endl;
						this->n_lines[index].n_blocks[0].block_info();
						cout << " L1B bloque 0" << endl;
						L1B.n_lines[index].n_blocks[0].block_info();
						cout << " L1B bloque 1" << endl;
						L1B.n_lines[index].n_blocks[1].block_info();
						cout << "" << endl;
						return dato2;
					}						
			} else {
				cout << "" << endl;
				cout << " Lineas de los caches L1 despues de la lectura " << endl;
				cout << " L1A bloque 1" << endl;
				this->n_lines[index].n_blocks[1].block_info();
				cout << " L1A bloque 0" << endl;
				this->n_lines[index].n_blocks[0].block_info();
				cout << " L1B bloque 0" << endl;
				L1B.n_lines[index].n_blocks[0].block_info();
				cout << " L1B bloque 1" << endl;
				L1B.n_lines[index].n_blocks[1].block_info();
				cout << "" << endl;
				return dato;
			}
	
		}

	Line Cache_L1::get_line(int index){
			Line linea = n_lines[index];
			return linea;
		}
