#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void main(){
	/*
		size - size of array
		start, stop - mix and max values of random

		inputArray - input array container

		min - minimal odd from inputArray

		output - string printing to console
	*/
	const int size = 10;
	int start = 10, stop = 90;

	int inputArray[size];

	char output[255];

	int min = 0;

	srand(time(NULL));

	for (int i = 0; i < size; i++){
		/*set new inputArray random digit*/
		inputArray[i] = rand() % (stop - start) + start;

		/*print inputArray element*/
		cout << inputArray[i] << "\n";

		/*check if element is odd*/
		if (inputArray[i] % 2) {
			/*
				if we found first odd element 
				or this element less than min
				replacing min value
			*/
			if ((min == 0) || (inputArray[i] < min)){
				min = inputArray[i];
			}
		}
	}

	if (min == 0) {
		sprintf_s(output, "\nThere is no odd numbers\n");
	}
	else {
		sprintf_s(output, "\nMinimal odd = %i\n", min);
	}

	cout << output;

}