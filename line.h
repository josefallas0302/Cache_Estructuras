#ifndef LINE_CLASS
#define LINE_CLASS

#include <stdio.h>
#include <iostream> 
#include <vector>
#include "block.h"

class Line {
	private:
		int n_sets;
                vector <Block> n_blocks;
		
		//friend void MESI(char, vector <int>, Cache_L1 , Cache_L1 , Cache_dir);	
	public:
// Constructor, toma n_bloques por set y genera una lista con bloques invalidos
	
	Line (int set);

	bool compare(int, int );
	
	void write_in_line(int, int);

	int read_in_line(int);

	Block get_block(int);
}; 
#endif

