#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void main(){
	/*
		size - size of arrays
		start, stop - mix and max values of random
		inputArr - input array container
		outputArr - output array container
		output - string printing to console
	*/

	const int size = 10;
	int start = -50, stop = 50;
	int inputArr[size], outputArr[size];

	char output[255];

	/* modifing random */

	srand(time(NULL));

	/* filling first array */

	for (int i = 0; i < size; i++) {
		inputArr[i] = rand() % (stop - start) + start;
	}

	/* 
		reversIndex - index of element from inputArr
	*/

	int reversIndex = size;

	/* reversing array */

	for (int i = 0; i < size; i++) {
		reversIndex--;
		outputArr[i] = inputArr[reversIndex];
	}

	/* printing arrays */

	for (int i = 0; i < size; i++) {
		sprintf_s(output, "%i \t %i \n", inputArr[i], outputArr[i]);
		cout << output;
	}
}
