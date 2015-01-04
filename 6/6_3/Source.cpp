#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void main(){
	/*
		size - size of array
		needToRepeat - how many times must repeat digit
		start, stop - mix and max values of random

		inputArray - input array container
		repeatArray - array contains [digit][repeats]
		
		repeatIndex - index of repeatArray
		repeats - digit repeat counter

		checkRepeats - var to check existanse of digit in repeatArray

		output - string printing to console
	*/
	const int size = 50;
	int needToRepeat = 2;
	int start = 0, stop = 9;
	
	int inputArray[size];

	int repeatArray[size][2] = {};
	int repeatIndex = 0;
	int repeats = 0;

	bool checkRepeats;

	char output[255];

	/* modifing random */
	srand(time(NULL));

	/* filling and printing inputArray */
	for (int i = 0; i < size; i++){
		inputArray[i] = rand() % (start - stop) + start;
		cout << inputArray[i] << " ";
	}

	for (int i = 0; i <= size; i++) {

		checkRepeats = true;

		/*check if this digit exist in repeatArray*/

		for (int j = 0; j < size; j++) {
			if (repeatArray[j][1] == 0) {
				/*items in repeatArray end*/
				break;
			}
			if (inputArray[i] == repeatArray[j][0]) {
				/*this digi already checked*/
				checkRepeats = false;
				break;
			}
		}

		/*calculating repeats*/

		if (checkRepeats) {
			/*reset repeats counter*/
			repeats = 0;
			for (int j = i; j <= size; j++) {
				if (inputArray[j] == inputArray[i]) {
					/*catch repeat*/
					repeats++;
				}
			}
			if (repeats >= needToRepeat){
				/*filling repeatArray*/
				repeatArray[repeatIndex][0] = inputArray[i];
				repeatArray[repeatIndex][1] = repeats;
				repeatIndex++;
			}
		}	
	}

	/*Printing repeats array*/

	for (int i = 0; i < size; i++) {
		if (repeatArray[i][1] == 0) {
			break;
		}
		sprintf_s(output, "\n%i repeats %i times\n", repeatArray[i][0], repeatArray[i][1]);
		cout << output;
	}

}