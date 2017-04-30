#include "block.h"


		Block::Block(int valid,char state, int tag, int data, char died){
			B_state = state;
			B_tag = tag;
			B_data = data;
			B_died = died;
			B_valid = valid;
		}

		int Block::get_tag (void){
		  return B_tag;
		}

		void Block::set_tag (int new_tag){
		  B_tag = new_tag;
		}

  		int Block :: get_valid (void){
		  return B_valid;
		}

		void Block :: set_valid (int new_valid){
		  B_valid = new_valid;
		}

  		char Block :: get_state (void){
		  return B_state;
		}

		void Block :: set_state (char new_state){
		  B_state = new_state;
		}

    		char Block :: get_died (void){
		  return B_died;
		}

		void Block :: set_died (char new_died){
		  B_died = new_died;
		}


               	int Block :: get_data (void){
		    return B_data;
		}

                void Block :: set_data (int new_data){
		    B_data = new_data;

		}

		void Block :: block_info (void) {
			cout << "Estado: " << B_state << " Tag: " << B_tag << " Dato: " << B_data << " LRU: " << B_died << " Valid " << B_valid << endl;    
		}


