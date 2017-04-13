
class Block {
	private:

		int B_valid;
		char B_state;
		int B_tag;
             	int B_data[32];
                char B_died; 

	public:

		//Default constructor (Default Ctor)
                Block(int valid, char state, int tag, int data[], char died) : B_valid(valid), B_state(state), B_tag(tag), B_died(died){
                 for(int i=0; i<32; i++){
		   B_data[i] = data[i];
                 }
		  return;
		}

		int get_tag (void){
		  return B_tag;
		}

		void set_tag (int new_tag){
		  B_tag = new_tag;
		}

  		int get_valid (void){
		  return B_valid;
		}

		void set_valid (int new_valid){
		  B_valid = new_valid;
		}

  		char get_state (void){
		  return B_state;
		}

		void set_state (char new_state){
		  B_state = new_state;
		}

    		char get_died (void){
		  return B_died;
		}

		void set_died (char new_died){
		  B_died = new_died;
		}

                int get_data (int i){
		    return B_data[i];
		}

                void set_data (int new_data[]){
		  for(int i=0; i<32; i++){
		    B_data[i] = new_data[i];
		  }
		}

};
