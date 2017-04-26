#include <stdio.h>
#include <iostream> 
#include <vector>
#include "block.cpp"
#include <math.h>
#include "mem.cpp"

using namespace std;

class Cache_dir {

	private:
                std :: vector <Block> c_block;
		int num_block;
		//char c_state;

	public :
	       Cache_dir (int blocks) : num_block(blocks){
		  Block newblock = Block(0, 'i', 0, 0, 'v');
		  for(int i=0; i<blocks; i++){
		    c_block.insert( c_block.begin(), newblock);
		  }
		  return;
		}

		//Escribe en el cache, recibe la direccion de memoria y el dato
		void write_dir (vector <int> binario, int new_data, memory CPU_mem){
			int iterator = binario.size(); //Tamano de la direccion en binario
			int index = 0;
			int parameter1 = 0;
			for(int i=iterator-1; i>iterator-13; i--){
				index = index + binario[i]*pow(2,parameter1);
				parameter1 = parameter1 + 1;
			} // Convierte el index de binario a decimal (12 bits para el index)

			int tag = 0;
			int parameter2 = 0;
			for(int i=iterator-13; i>=0; i--){
				tag = tag + binario[i]*pow(2,parameter2);
				parameter2 = parameter2 + 1;
			} //Convierte el tag de binario a decimal (iterator-index = bits de tag)

			// Sobreescribe el tag y el dato en el cache
			c_block[index].set_tag(tag);
			c_block[index].set_data(new_data);
			c_block[index].set_valid(1);
			CPU_mem.set_dir(binario, new_data);
			
			return;
		}

		//Lee del cache, recibe la direccion de memoria proveniente del cache L1
		int read_dir(vector <int> binario, memory CPU_mem ){

			int iterator = binario.size(); //Tamano de la direccion en binario
			int index = 0;
			int parameter1 = 0;
			for(int i=iterator-1; i>iterator-13; i--){
				index = index + binario[i]*pow(2,parameter1);
				parameter1 = parameter1 + 1;
			} // Convierte el index de binario a decimal (12 bits para el index)

			int tag = 0;
			int parameter2 = 0;
			for(int i=iterator-13; i>=0; i--){
				tag = tag + binario[i]*pow(2,parameter2);
				parameter2 = parameter2 + 1;
			} //Convierte el tag de binario a decimal (iterator-index = bits de tag)

			if ( c_block[index].get_tag() == tag && c_block[index].get_valid()== 1){
				return c_block[index].get_data();
			}else {
				c_block[index].set_tag(tag);
				c_block[index].set_data(CPU_mem.find_dir(binario));
				c_block[index].set_valid(1);
				return CPU_mem.find_dir(binario);
			} // Busca el dato en el cache o en la memoria
		}
};

//int main(){
//};











