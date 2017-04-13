#include <line.h>


class Line {
	private:
		int n_sets;
		list <block> n_blocks;		
	public:
// Constructor, toma n_bloques por set y genera una lista con bloques invalidos
		Line (int sets) : n_sets(sets){
			n_blocks.assign();
			for( int i=0 ; i<n_sets, i++){
				n_blocks.push_front(Block(0,'i',0,0));
			return;
			}
		}
// Carga un bloque al set
		set_block (int n , block) {
			
		}
		
};
