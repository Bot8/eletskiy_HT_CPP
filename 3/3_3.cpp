#include <iostream>
using namespace std;
void main(){
	char output[255];
	int n, faktorial;
	cout << "Enter positive number: ";
	cin >> n;
	if (n < 0) {
		sprintf(output, "Number must be positive\n");
	} else {
		faktorial = 1;
		if (n > 1) {
			for (int i = 2; i <= n; i++) {
				faktorial *= i;
			}
		}
		sprintf(output, "%i!=%i\n", n, faktorial);
	}

	cout << output;
}