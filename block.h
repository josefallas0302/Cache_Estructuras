#ifndef BLOCK_CLASS
#define BLOCK_CLASS

#include <vector>
#include <iostream>
using namespace std;

class Block{
	private:
		char B_state;
		int  B_tag;
		int  B_valid;
		int  B_data;
                char B_died; 

	//	friend void MESI (Block);

	public:

		//Default constructor (Default Ctor)

		Block(int,char, int, int, char);

		int get_tag (void);

		void set_tag (int);

  		int get_valid (void);

		void set_valid (int new_valid);

 		char get_state (void);

		void set_state (char new_state);

    		char get_died (void);

		void set_died (char new_died);

                int get_data (void);

                void set_data (int new_data);
		
		void block_info(void);
};

#endif 
