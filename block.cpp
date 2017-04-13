#include <stdio.h>
#include <iostream> 
using namespace std;


class Block {
	private:
		int valid;
		int modified;
		int exclusive;
		int shared;
		int invalid;
		int tag;
		int data;
	public:
		void SetSize (int size) {
			c_size = size;
		}
		void SetType (int type) {
			c_type = type;
		}
		void SetBlock (int block){
			c_block_size = block;
		}
		void GetState (char state){
			c_state = state;
		}
		
	/*	cargar_dato(int set, ):
			for(i=0,i<)		
*/


};
