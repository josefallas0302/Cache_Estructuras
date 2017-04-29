#include "line.h"

using namespace std;
// Constructor, toma n_bloques por set y genera una lista con bloques invalidos

  	Line::Line (int sets) : n_sets(sets) {
		int bloque;
		Block newbloque = Block(0, 'M',0,bloque, 'V');
        	for( int i=0 ; i<n_sets; i++){
			n_blocks.insert( n_blocks.begin(), newbloque);
       		}
  		return;
  	}

	bool Line::compare(int tag_R, int block){              
		int tag_B = n_blocks[block].get_tag();
		if (tag_R == tag_B && n_blocks[block].get_state() != 'i'){
			return true;
		}else{
			return false;
		}
	}


	void Line::write_in_line(int data_R, int tag_R){
		char died = n_blocks[0].get_died();
		if(died == 'V'){
			n_blocks[0].set_data(data_R);
			n_blocks[0].set_tag(tag_R);
			n_blocks[0].set_died('N');
			n_blocks[1].set_died('V');
		}
		else{
			n_blocks[1].set_data(data_R);
			n_blocks[1].set_tag(tag_R);
			n_blocks[1].set_died('N');
			n_blocks[0].set_died('V');
		}
	}

/*	 void write_in_line(int data_R, int tag_R){
			bool block_0 = compare(tag_R, 0);
			bool block_1 = compare(tag_R, 1);  
			if( block_0 || block_1 == false){
				pseudo_write(data_R, tag_R);
			}
	}*/

	int Line::read_in_line (int tag_R){
			bool block_0 = compare(tag_R,0);
			bool block_1 = compare(tag_R,1);
			if (block_0 == true){ 
				cout<<"hit"<<endl;
				return n_blocks[0].get_data();
			}
			if (block_1 == true){
				cout<<"hit"<<endl;
				return n_blocks[1].get_data();
			}
			else {
				cout <<"miss"<< endl;
				return -1;
			}
	}
	/*vector <int> give_direc (int tag_R){
				

	}*/


/*int main(){
	int data_1 [32] = {31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int data_2 [32] = {63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32};

 	Line linea(2);
	int a = linea.read_in_line(0, 3);
	int b;
	int c;

	cout << "read_result = "  << a <<  endl;


	cout << "Estoy escribiendo Tag = 1" <<  endl;	
	linea.write_in_line(data_1,1);

	cout << "Estoy bucando Tag = 1" <<  endl;
	
	for (int i = 0; i<32; i++){
	b = linea.read_in_line(1, i);
	cout << "read_result = "  << b <<  endl;
	}
	cout << "Estoy bucando Tag = 2" <<  endl;
	for(int i=0; i<32; i++){
	c = linea.read_in_line(2,i);
	cout << "read_result = "  << c <<  endl;
	}	

	cout << "Estoy escribiendo Tag = 2" <<  endl;	
	linea.write_in_line(data_2,2);

	cout << "Estoy bucando Tag = 2" <<  endl;
	for(int i=0; i<32; i++){
	c = linea.read_in_line(2,i);
	cout << "read_result = "  << c <<  endl;
	}
	return 0;
};*/

