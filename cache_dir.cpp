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

		
		void write_dir (char dir[], int data_R[32]){
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
			
			int iterator = binario.size();
			int offset = binario[0]*1 + binario[1]*2 + binario[2]*4 + binario[3]*8 + binario[4]*16 ;
			int index = binario[5]*1 + binario[6]*2 + binario[7]*4 + binario[8]*8 + binario[9]*16 + binario[10]*32 + binario[11]*64 + binario[12]*128 + binario[13]*256 + binario[14]*512 + binario[15]*1024 + binario[16]*2048 ;
			int tag = 0;
			int parameter = 0;
			for(int i=17; i<iterator; i++){
				tag = tag + binario[i]*pow(2,parameter);
				parameter = parameter + 1;
			}

			c_block[index].set_tag(tag);
			c_block[index].set_data(data_R);
			//for(int i=0; i<dir_size*4; i++){
			//	cout << binario[i] << endl;
			//}
			return;
		}

		std :: vector <int> read_dir(char dir[]){
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
			
			int iterator = binario.size();
			int offset = binario[0]*1 + binario[1]*2 + binario[2]*4 + binario[3]*8 + binario[4]*16 ;
			int index = binario[5]*1 + binario[6]*2 + binario[7]*4 + binario[8]*8 + binario[9]*16 + binario[10]*32 + binario[11]*64 + binario[12]*128 + binario[13]*256 + binario[14]*512 + binario[15]*1024 + binario[16]*2048 ;
			int tag = 0;
			int parameter = 0;
			for(int i=17; i<iterator; i++){
				tag = tag + binario[i]*pow(2,parameter);
				parameter = parameter + 1;
			}

			if ( c_block[index].get_tag() == tag){
				return c_block[index].get_data();
			}else {
				
			}
		}
};

int main(){

//Cache_dir newcache = Cache_dir(10, 3);
//newcache.write_dir("A09");

};











