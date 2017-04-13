#include <stdio.h>
#include <iostream> 
#include <list>
#include "block.cpp"

using namespace std;

class Line {
	private:
		int n_sets;
                vector <Block> n_blocks;		
	public:
// Constructor, toma n_bloques por set y genera una lista con bloques invalidos

  Line (int sets) : n_sets(sets) {
        for( int i=0 ; i<n_sets; i++){
	n_blocks.push_front(Block(0,'i',0,0));
       }
  	return;
  	}
// Devuelve el bloque
		Block get_block (int n) {
			Block Block_n
			return Block_n
		}

		
// Carga un bloque al set				
		void set_block (int n, Block newBlock) {
			n_blocks[n] = newBlock;
		}
		
};

int main(){
 /* Line m = Line(2);
  Block a = m.n_blocks.begin();
  int b = a.get_tag();
  cout << b << endl;*/
	return 0;
};

