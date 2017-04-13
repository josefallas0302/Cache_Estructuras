#include <stdio.h>
#include <iostream> 
#include <list>
#include "block.cpp"

using namespace std;

class Line {
	private:
		int n_sets;
                list <Block> n_blocks;		
	public:
// Constructor, toma n_bloques por set y genera una lista con bloques invalidos
  Line (int sets) : n_sets(sets) {
        for( int i=0 ; i<n_sets; i++){
	n_blocks.push_front(Block(0,'i',0,0));
       }
  	return;
  	}
		
// Carga un bloque al set
		/*set_block (int n , block) {
			n_block
		}*/
	


	bool compare(int tag_R, int block){              //FIXME
		int tag_B = n_blocks[block].get_tag();
		if (tag_R == tag_B){
			return true;
		}else{
			return false;
		}
	}
	

	void write(int data_R, int tag_R){
		char died = n_blocks[0].get_died();
		if(died == 'V'){
			n_blocks[0].set_data(data_R);
			n_blocks[0].set_tag(tag_R);
			n_blocks[0].set_died('N');
			n_blocks[1].set_died('V');
		}else{
			n_blocks[1].set_data(data_R);
			n_blocks[1].set_tag(tag_R);
			n_blocks[1].set_died('N');
			n_blocks[0].set_died('V');
		}
	}

	

};

int main(){
  Line m = Line(2);
  Block a = m.n_blocks.begin();
  int b = a.get_tag();
  cout << b << endl;
};
