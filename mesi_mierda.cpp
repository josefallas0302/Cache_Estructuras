#include "cache.h"
#include "cache_dir.h"


void MESI (char inst, vector <int> direction ,Cache_L1 cache_1 , Cache_L1 cache_2, Cache_dir cache_L2, memory memoria){
		//char initial_state

// Setea el tag y los index de cada cache
		vector <int> binario = direction;
		int iterator = binario.size(); //Tamano de la direccion en binario
		int index_L2 = 0;
		int parameter1 = 0;
		for(int i=iterator-1; i>iterator-13; i--){
			index_L2 = index_L2 + binario[i]*pow(2,parameter1);
			parameter1 = parameter1 + 1;
		} // Convierte el index de binario a decimal (12 bits para el index)
		
		int tag = 0;  // TAG es lo importante Aquí
		int index = 0;	// Index es lo importante aquí

		int parameter = 0;			
		
		for(int i=0; i<8; i++){
			index = index + binario[i]*pow(2,parameter);
			parameter = parameter + 1;
		}
			
		parameter = 0;
		for(int i=8; i<iterator; i++){
			tag = tag + binario[i]*pow(2,parameter);
			parameter = parameter + 1;
		}
		

		cout << "index L2: " << index_L2 << "index L1: " << index << "tag L1: " << tag << endl;

		if(inst == 'S'){
			for(int i = 0; i<2 ; i++){
				//En  caso
				if(cache_1.n_lines[index].n_blocks[i].get_tag() == tag && cache_1.n_lines[index].compare(tag, i) == true){
				cache_1.n_lines[index].n_blocks[i].set_state('M');
				char initial_state = cache_2.n_lines[index].n_blocks[i].get_state();
				if(initial_state == 'M'){
					int dato = cache_2.n_lines[index].n_blocks[i].get_data();
					cache_L2.write_dir(direction, dato, memoria);
					}

				cache_2.n_lines[index].n_blocks[i].set_state('I');
				cache_L2.set_valid_dir(index_L2,0);
				}
			}
		}
		if( inst == 'L'){
		for(int i=0; i < 2 ; i++){
			for(int j=0; j<2; j++){
				if (cache_1.n_lines[index].n_blocks[i].get_tag() == cache_2.n_lines[index].n_blocks[j].get_tag()){
					cache_1.n_lines[index].n_blocks[i].set_state('S');
					cache_2.n_lines[index].n_blocks[i].set_state('S');
				}
				else{
					cache_1.n_lines[index].n_blocks[i].set_state('E');
					cache_2.n_lines[index].n_blocks[i].set_state('I');
				}
				}
			}
		}
	}
