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
		//friend void MESI;	
	public:
// Constructor, toma n_bloques por set y genera una lista con bloques invalidos
	
	Line (int set);

	bool compare(int, int block);
	
	void write_in_line(int, int);

	int read_in_line(int);

}; 
#endif

