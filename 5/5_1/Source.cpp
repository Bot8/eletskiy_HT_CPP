#include <iostream>
using namespace std;
void main(){
	bool simple;
	for (int i = 3; i <= 1000; i++) {
		simple = true;
		for (int j = 2; j < i; j++) {
			if (i%j == 0) {
				simple = false;
				break;
			}		
		}
		if (simple) {
			cout << i << " ";
		}
	}
}