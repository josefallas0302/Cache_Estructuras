
class Block {
	private:

		int B_valid;
		char B_state;
		int B_tag;
		int B_data;

	public:

		//Default constructor (Default Ctor)
		Block(int valid, char state, int tag, int data) : B_valid(valid), B_state(state), B_tag(tag), B_data(data){
			return;
		}

		int get_tag (void){
		  return B_tag;
		}

		void set_tag (int new_tag){
		  B_tag = new_tag;
		}

};

