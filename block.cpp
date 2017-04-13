
class Block {
	private:

		int B_valid;
		char B_state;
		int B_tag;
             // int N = 32;
             //	int B_data[32];
                int B_data;

	public:

		//Default constructor (Default Ctor)
               Block(int valid, char state, int tag, int data) : B_valid(valid), B_state(state), B_tag(tag), B_data(data){
                 // for(int i=0; i<32; i++){
                 // B_data[i] = data[i];
                 // }
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

  		int get_state (void){
		  return B_state;
		}

		void set_state (int new_state){
		  B_state = new_state;
		}
};

