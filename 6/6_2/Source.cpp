#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void main(){
	/*
		size - size of arra
		start, stop - mix and max values of random
		inputArray - input array container
		evenSumm, oddSumm  - summ of even/odd elements from inputArray

		output - string printing to console
	*/
	const int size = 10;
	int start = -9, stop = 9;
	int evenSumm = 0, oddSumm = 0;

	int inputArray[size];

	char output[255];

	/* modifing random */
	srand(time(NULL));

	for (int i = 0; i < size; i++) {

		/* set "i" elment in inputArray */
		inputArray[i] = rand() % (stop - start) + start;

		/* print "i" elment in inputArray */
		cout << inputArray[i] << "\n";

		if (inputArray[i] % 2) {
			/* "i" elment from inputArray is odd (inputArray[i] % 2 != 0) */
			oddSumm += inputArray[i];
		}
		else {
			/* "i" elment from inputArray is even */
			evenSumm += inputArray[i];
		}
	}

	/* printing array */

	sprintf_s(output, "\nSum of even = %i \nSum of odd = %i \n\n", evenSumm, oddSumm);

	cout << output;
}