#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

class memory {

	private:
		std :: vector <vector <int> > l_mem;
		int size_line;

	public:
		memory (int line) : size_line(line){
			for (int i=0; i<size_line; i++){
				vector <int> newvector ;
				newvector.insert(newvector.begin(), 666666) ;
				newvector.insert(newvector.begin(), i) ;
				l_mem.insert(l_mem.end(), newvector) ;
			}
			return;
		}

		// Busca el dato en memoria
		int find_dir (vector <int> binario){

			int iterator = binario.size();
			int dir_dec = 0;
			for(int i=0; i<iterator; i++){
				dir_dec = dir_dec + binario[i]*pow(2,i);
			} //Convierte la direccion de binario a decimal

			for (int i=0; i<size_line; i++){
				if(l_mem[i][1] == dir_dec){
					return l_mem[i][0];
				}
			} //Compara la direccion con cada linea de memoria y devuelve el data
		}



};

//int main(){
//};
