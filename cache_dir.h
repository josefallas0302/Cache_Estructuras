#ifndef CACHE_DIR_CLASS
#define CACHE_DIR_CLASS
#include <stdio.h>
#include <iostream> 
#include <vector>
#include "block.h"
#include <math.h>
#include "mem.h"
//#include "cache.h"




using namespace std;

class Cache_dir {

	private:
                std :: vector <Block> c_block;
		int num_block;
		//friend void MESI(char, vector <int>, Cache_L1 , Cache_L1 , Cache_dir);

	public :

	       Cache_dir (int blocks);


		//Escribe en el cache, recibe la direccion de memoria y el dato
		void write_dir (vector <int> binario, int new_data, memory CPU_mem);

		//Lee del cache, recibe la direccion de memoria proveniente del cache L1
		int read_dir(vector <int> binario, memory CPU_mem );

		void set_valid_dir(int index, int valid);
};

#endif 









