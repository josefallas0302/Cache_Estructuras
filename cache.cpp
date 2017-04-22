#include <stdio.h>
#include <iostream> 
#include <vector>
#include <math.h>
#include "line.cpp"

using namespace std;


class Cache {

	private:
		vector <Line> n_lines;

	public :
		Cache (int numero_lineas){
				for (int i = 0; i < numero_lineas; i++ ){
					n_lines.push_back(Line(2));

		}
	
	}
		void write_data (vector <int> memory_direction, int dato){
			
	}

		int read_data (vector <int> memory_direction){
			int dato;

			vector <int> binario = memory_direction;
			int iterator = binario.size();
			int tag = 0;  // TAG es lo importante Aquí
			int index = 0;	// Index es lo importante aquí


			int parameter = 0;			
			
			for(int i=0; i<8; i++){
				index = tag + binario[i]*pow(2,parameter);
				parameter = parameter + 1;
			}

			
			parameter = 0;

			for(int i=8; i<iterator; i++){
				tag = tag + binario[i]*pow(2,parameter);
				parameter = parameter + 1;
			}
			
			
			dato = n_lines[index].read_in_line(tag);
					return dato;
		}	

	
};

int main() {
	
	return 0;
};









