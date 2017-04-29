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

<<<<<<< HEAD

		int read_data_L1 (vector <int>,Cache_dir, memory);	


=======
		int read_data_L1 (vector <int>);	

>>>>>>> 8d7fd27b6680cd926e76a39f40a95f56f31a31ff
		void Load_from_mem(vector <int>, Cache_dir, memory);
};
#endif
