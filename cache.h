#ifndef CACHE_L1_CLASS
#define CACHE_L1_CLASS

#include <stdio.h>
#include <iostream> 
#include <vector>
#include <math.h>
#include "line.h"
#include "cache_dir.h"
#include "mem.h"

using namespace std;


class Cache_L1 {

	private:
		vector <Line> n_lines;
		//friend void MESI(char, vector <int>, Cache_L1 , Cache_L1 , Cache_dir);
	public :
		Cache_L1 (int);
			
		void write_data_L1 (vector <int>, int);


		int read_data_L1 (vector <int>,Cache_dir, memory);	


		void Load_from_mem(vector <int>, Cache_dir, memory);
	
		Line get_line(int);

};
#endif
