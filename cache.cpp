#include <stdio.h>
#include <iostream> 
using namespace std;

int main(){
	return 0;
};

class Cache {
	private:
		int c_size;
		int c_type;
		int c_block_size;
		char c_state;
	public :
		void Cache (int c_size, int c_type, int c_block_size ) {
				c_size = size;
				c_type = type;
				c_block_size = block;
				c_state = state;
		}

		void Cache (int size ) {
			c_size = size;
		}

		void SetType (int type ){
			c_type = type;
		}
		void SetBlock (int block ) {
			c_block_size = block;
		}
		void GetState (char state){
			c_state = state;
		}
	
	
};
