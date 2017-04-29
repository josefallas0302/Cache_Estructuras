#include <stdio.h>
#include <iostream> 
#include <vector>
#include <math.h>
#include "line.h"
#include "cache_dir.h"
#include "mem.h"

#ifndef CACHE_L1_CLASS
#define CACHE_L1_CLASS

using namespace std;


class Cache_L1 {

	private:
		vector <Line> n_lines;
		//friend void MESI;

	public :
		Cache_L1 (int);
			
		void write_data_L1 (vector <int>, int);


		int read_data_L1 (vector <int>,Cache_dir, memory);	


		int Load_from_mem(vector <int>, Cache_dir, memory);
};
#endif
