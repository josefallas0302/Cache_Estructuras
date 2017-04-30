#include <stdio.h>
#include <vector>
#include <math.h>
#include <iostream> 

#ifndef MEM_CLASS
#define MEM_CLASS

using namespace std;

class memory {

	private:
		std :: vector <int> l_mem;
		int size_line;

	public:

		memory (int line);
		// Busca el dato en memoria
		int find_dir (vector <int> binario);

		// Escribe el dato a memoria
		void set_dir (vector <int> binario, int new_data);

};

#endif 
