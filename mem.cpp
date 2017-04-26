#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

class memory {

	private:
		std :: vector <int> l_mem;
		int size_line;

	public:
		memory (int line) : size_line(line){
			for (int i=0; i<size_line; i++){
				l_mem.insert(l_mem.end(), 666666) ;
			}
			return;
		}

		// Busca el dato en memoria
		int find_dir (vector <int> binario){

			int iterator = binario.size();
			int dir_dec = 0;
			int parameter = 0;
			for(int i=iterator-1; i>=0; i--){
				dir_dec = dir_dec + binario[i]*pow(2,parameter);
				parameter = parameter +1;
			} //Convierte la direccion de binario a decimal

			return l_mem[dir_dec];
			//Compara la direccion con cada linea de memoria y devuelve el data
		}

		// Escribe el dato a memoria
		void set_dir (vector <int> binario, int new_data){

			int iterator = binario.size();
			int dir_dec = 0;
			int parameter = 0;
			for(int i=iterator-1; i>=0; i--){
				dir_dec = dir_dec + binario[i]*pow(2,parameter);
				parameter = parameter +1;
			} //Convierte la direccion de binario a decimal

			l_mem[dir_dec] = new_data;
			 //Compara la direccion con cada linea de memoria y devuelve el data
		}


};

//int main(){
//};
