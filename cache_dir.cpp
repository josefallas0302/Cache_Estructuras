#include <stdio.h>
#include <iostream> 
#include <vector>
#include "block.cpp"

class Cache_dir {

	private:
                std :: vector <Block> c_block;
		int num_block;
		//int c_block_size;
		//char c_state;

	public :
	       Cache_dir (int blocks) : num_block(blocks) {
		  int vacio[32];
		  Block newblock = Block(0, 'i', 0, vacio, 'v');
		  for(int i=0; i<blocks; i++){
		    c_block.insert( c_block.begin(), newblock);
		  }
		  return;
		}


};

int main(){
};











