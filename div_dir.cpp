#include <stdio.h>
#include <iostream> 
#include <vector>
#include <math.h>
#include <cstring>
#include <string>

/*#ifndef "BLOCK_CLASS"
#define "BLOCK_CLASS"
*/
using namespace std;

vector <int> div_dir(string dir, int dir_size){
		vector <int> binario;
		for (int i=0; i<dir_size; i++){
				if(dir[i] == '0'){
					binario.push_back(0);
					binario.push_back(0);
					binario.push_back(0);
					binario.push_back(0);
				}else if(dir[i] == '1'){
					binario.push_back(0);
					binario.push_back(0);
					binario.push_back(0);
					binario.push_back(1);
				}else if(dir[i] == '2'){
					binario.push_back(0);
					binario.push_back(0);
					binario.push_back(1);
					binario.push_back(0);
				}else if(dir[i] == '3'){
					binario.push_back(0);
					binario.push_back(0);
					binario.push_back(1);
					binario.push_back(1);
				}else if(dir[i] == '4'){
					binario.push_back(0);
					binario.push_back(1);
					binario.push_back(0);
					binario.push_back(0);
				}else if(dir[i] == '5'){
					binario.push_back(0);
					binario.push_back(1);
					binario.push_back(0);
					binario.push_back(1);
				}else if(dir[i] == '6'){
					binario.push_back(0);
					binario.push_back(1);
					binario.push_back(1);
					binario.push_back(0);
				}else if(dir[i] == '7'){
					binario.push_back(0);
					binario.push_back(1);
					binario.push_back(1);
					binario.push_back(1);
				}else if(dir[i] == '8'){
					binario.push_back(1);
					binario.push_back(0);
					binario.push_back(0);
					binario.push_back(0);
				}else if(dir[i] == '9'){
					binario.push_back(1);
					binario.push_back(0);
					binario.push_back(0);
					binario.push_back(1);
				}else if(dir[i] == 'A'){
					binario.push_back(1);
					binario.push_back(0);
					binario.push_back(1);
					binario.push_back(0);
				}else if(dir[i] == 'B'){
					binario.push_back(1);
					binario.push_back(0);
					binario.push_back(1);
					binario.push_back(1);
				}else if(dir[i] == 'C'){
					binario.push_back(1);
					binario.push_back(1);
					binario.push_back(0);
					binario.push_back(0);
				}else if(dir[i] == 'D'){
					binario.push_back(1);
					binario.push_back(1);
					binario.push_back(0);
					binario.push_back(1);
				}else if(dir[i] == 'E'){
					binario.push_back(1);
					binario.push_back(1);
					binario.push_back(1);
					binario.push_back(0);
				}else if(dir[i] == 'F'){
					binario.push_back(1);
					binario.push_back(1);
					binario.push_back(1);
					binario.push_back(1);
				}
				
				
			}
							
		return binario;
		}


/*void MESI (char inst, vector <int> direction ,Cache cache_1 , Cache cache_2, Cache_dir cache_L2){
		int index = 0;
		int tag = 0;
		if(char inst == "S"){
			for(int i = 0; i<2 ; i++){
				if(cache_1.n_lines[index].n_blocks[i]== ){
				cache_1.n_lines[index].n_blocks[i].set_state('M');
				cache_L2.c_blocks[tag]
			}
		}
		if(char inst == "C"){
		for(int i=0; i < 2 ; i++){
			for(int j=0; j<2; j++){
				if (cache_1.n_lines[index].n_blocks[i] == cache_2.n_lines[index].n_blocks[j]){
					cache_1.n_lines[index].n_blocks[i].set_state('S');
					cache_2.n_lines[index].n_blocks[i].set_state('S');
				}
			} 		
		}
*/
