ls
#include <stdio.h>
#include <iostream> 
using namespace std;

class Cache (int c_size, int c_type, int c_block_size) {
	private:
		int c_size;
		int c_type;
		int c_block_size;
		char c_state;
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
