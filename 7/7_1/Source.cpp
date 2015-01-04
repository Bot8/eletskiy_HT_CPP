#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
void main(){

	/*
		arHeight - height of input array
		arWidth - width of input array
		inputArrray - array with random values

		start, stop - mix and max values of random

		counter - counter of zero values

		output - string printing to console
	*/

	const int arHeight = 3, arWidth = 4;
	int inputArrray[arHeight][arWidth] = {};

	int start = 0, stop = 9;

	int counter = 0;

	char output[255];

	/*modifying random*/
	srand(time(NULL));

	/*process array*/
	for (int i = 0; i < arHeight; i++) {
		for (int j = 0; j < arWidth; j++) {
			/*Generate value*/
			inputArrray[i][j] = rand() % (stop - start) + start;
			if (inputArrray[i][j] == 0) {
				/*value equals zero*/
				counter++;
			}			
			/*print generated value*/
			cout << inputArrray[i][j] << " ";
		}
		cout << "\n";
	}
	/*Generate and print string with rezult*/
	sprintf_s(output, "\nThere are %i zero values in array\n", counter);
	cout << output;
}