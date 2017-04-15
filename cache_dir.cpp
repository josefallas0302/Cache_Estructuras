#include <stdio.h>
#include <iostream> 
#include <vector>
#include "block.cpp"
#include <math.h>

using namespace std;

class Cache_dir {

	private:
                std :: vector <Block> c_block;
		int num_block;
		int dir_size;
		//char c_state;

	public :
	       Cache_dir (int blocks, int size) : num_block(blocks), dir_size(size) {
		  int vacio[32];
		  Block newblock = Block(0, 'i', 0, vacio, 'v');
		  for(int i=0; i<blocks; i++){
		    c_block.insert( c_block.begin(), newblock);
		  }
		  return;
		}

		
		void write_dir (char dir[]){
			int result=0;
			for (int i=0; i<dir_size; i++){
				if(dir[i] == '0'){
					result = result + 0*pow(16,dir_size-1-i);
				}else if(dir[i] == '1'){
					result = result + 1*pow(16,dir_size-1-i);
				}else if(dir[i] == '2'){
					result = result + 2*pow(16,dir_size-1-i);
				}else if(dir[i] == '3'){
					result = result + 3*pow(16,dir_size-1-i);
				}else if(dir[i] == '4'){
					result = result + 4*pow(16,dir_size-1-i);
				}else if(dir[i] == '5'){
					result = result + 5*pow(16,dir_size-1-i);
				}else if(dir[i] == '6'){
					result = result + 6*pow(16,dir_size-1-i);
				}else if(dir[i] == '7'){
					result = result + 7*pow(16,dir_size-1-i);
				}else if(dir[i] == '8'){
					result = result + 8*pow(16,dir_size-1-i);
				}else if(dir[i] == '9'){
					result = result + 9*pow(16,dir_size-1-i);
				}else if(dir[i] == 'A'){
					result = result + 10*pow(16,dir_size-1-i);
				}else if(dir[i] == 'B'){
					result = result + 11*pow(16,dir_size-1-i);
				}else if(dir[i] == 'C'){
					result = result + 12*pow(16,dir_size-1-i);
				}else if(dir[i] == 'D'){
					result = result + 13*pow(16,dir_size-1-i);
				}else if(dir[i] == 'E'){
					result = result + 14*pow(16,dir_size-1-i);
				}else if(dir[i] == 'F'){
					result = result + 15*pow(16,dir_size-1-i);
				}
			}
			cout << result << endl;
			return;
		}


};

int main(){

Cache_dir newcache = Cache_dir(10, 6);
newcache.write_dir("F8A9BC");

};











