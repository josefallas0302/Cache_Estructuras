#include <stdio.h>
#include <iostream> 
#include <vector>
#include "block.cpp"

using namespace std;

class Line {
	private:
		int n_sets;
                vector <Block> n_blocks;		
	public:
// Constructor, toma n_bloques por set y genera una lista con bloques invalidos

  Line (int sets) : n_sets(sets) {
		int vec[32];
		Block newbloque = Block(0, 'i',0,vec, 'V');
        	for( int i=0 ; i<n_sets; i++){
			n_blocks.insert( n_blocks.begin(), newbloque);
       		}
  		return;
  	}

	bool compare(int tag_R, int block){              
		int tag_B = n_blocks[block].get_tag();
		if (tag_R == tag_B){
			return true;
		}else{
			return false;
		}
	}


	void write(int data_R[32], int tag_R){
		char died = n_blocks[0].get_died();
		if(died == 'V'){
			n_blocks[0].set_data(data_R);
			n_blocks[0].set_tag(tag_R);
			n_blocks[0].set_died('N');
			n_blocks[1].set_died('V');
		}
		else{
			n_blocks[1].set_data(data_R);
			n_blocks[1].set_tag(tag_R);
			n_blocks[1].set_died('N');
			n_blocks[0].set_died('V');
		}
	}

	 void set_V_NV (int tag_R){
			bool block_0 = compare(tag_R, 0);
			bool block_1 = compare(tag_R, 1);  
			if( block_0 & block_1 == false){

			}

			}
};

int main(){
 /* Line m = Line(2);
  Block a = m.n_blocks.begin();
  int b = a.get_tag();
  cout << b << endl;*/
	return 0;
};

