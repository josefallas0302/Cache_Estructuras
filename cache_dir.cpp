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
		int dir_size;
		//char c_state;

	public :
	       Cache_dir (int blocks, int size) : num_block(blocks), dir_size(size) {
		  int vacio = 0;
		  Block newblock = Block(0, 'i', 0, vacio, 'v');
		  for(int i=0; i<blocks; i++){
		    c_block.insert( c_block.begin(), newblock);
		  }
		  return;
		}

		//Escribe en el cache, recibe la direccion de memoria y el dato
		void write_dir (vector <int> binario, int new_data){
			int iterator = binario.size(); //Tamano de la direccion en binario
			int index = binario[0]*pow(2,0) + binario[1]*pow(2,1) + binario[2]*pow(2,2) + binario[3]*pow(2,3) + binario[4]*pow(2,4) + binario[5]*pow(2,5) + binario[6]*pow(2,6) + binario[7]*pow(2,7) + binario[8]*pow(2,8) + binario[9]*pow(2,9) + binario[10]*pow(2,10) + binario[11]*pow(2,11) ; // Convierte el index de binario a decimal (12 bits para el index)
			int tag = 0;
			int parameter = 0;
			for(int i=12; i<iterator; i++){
				tag = tag + binario[i]*pow(2,parameter);
				parameter = parameter + 1;
			} //Convierte el tag de binario a decimal (iterator-index = bits de tag)

			// Sobreescribe el tag y el dato en el cache
			c_block[index].set_tag(tag);
			c_block[index].set_data(new_data);

			return;
		}

		//Lee del cache, recibe la direccion de memoria proveniente del cache L1
		int read_dir(vector <int> binario, memory CPU_mem ){
			

			int iterator = binario.size(); //Tamano de la direccion en binario
			int index = binario[0]*pow(2,0) + binario[1]*pow(2,1) + binario[2]*pow(2,2) + binario[3]*pow(2,3) + binario[4]*pow(2,4) + binario[5]*pow(2,5) + binario[6]*pow(2,6) + binario[7]*pow(2,7) + binario[8]*pow(2,8) + binario[9]*pow(2,9) + binario[10]*pow(2,10) + binario[11]*pow(2,11) ; // Convierte el index de binario a decimal (12 bits para el index)
			int tag = 0;
			int parameter = 0;
			for(int i=12; i<iterator; i++){
				tag = tag + binario[i]*pow(2,parameter);
				parameter = parameter + 1;
			} //Convierte el tag de binario a decimal (iterator-index = bits de tag)

			if ( c_block[index].get_tag()){
				return c_block[index].get_data();
			}else {
				return CPU_mem.find_dir(binario);
			} // Busca el dato en el cache o en la memoria
		}
};

//int main(){
//};











