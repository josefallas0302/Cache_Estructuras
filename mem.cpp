#include <vector>


using namespace std;

class memory {

	private:
		std :: vector <vector <int> > l_mem;
		int size_line;

	public:
		memory (int line) : size_line(line){
			for (int i=0; i<size_line; i++){
				vector <int> newvector ;
				newvector.insert(newvector.end(), 666666) ;
				newvector.insert(newvector.end(), i) ;
				l_mem.insert(l_mem.end(), newvector) ;
			}
			return;
		}

		int find_tag (int old_tag){
			for (int i=0; i<size_line; i++){
				if(l_mem[i][1] == old_tag){
					return l_mem[i][0];
				}
			}
		}



};

int main(){
};
