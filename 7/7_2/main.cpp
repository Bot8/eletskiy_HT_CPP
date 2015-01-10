#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;
void main(){
	/*
		size - hidth and height of arrays

		outputArrSize - max vals in array areas
		outputArrKeys - task areas keys

		rndMin, rndMax- max and min values of random

		start, stop - min and max values to horizontal walk in array
		
		tempMax - tempolary container of max value in area
		firstIteration - flag to find first value in area
		output - printing result string
	*/
	
	const int size = 10, outputArrSize = 10;
	int inputArr[size][size];
	int outputArr[outputArrSize];
	char outputArrKeys[outputArrSize] = { 'а', 'б', 'в', 'г', 'д', 'е', 'ж', 'з', 'и', 'к'};
	int rndMin = -99, rndMax = 99;
	int start, stop;
	int tempMax;
	bool firstIteration = true;
	char output[1000];

	// Turn on russian locale
	setlocale(LC_ALL, ""); 

	//modify rand
	srand(time(NULL));	

	//Generate and print inputArr
	for (int i = 0; i < size; i++) {
		cout << "[";
		for (int j = 0; j < size; j++) {
			inputArr[i][j] = rand() % (rndMax - rndMin) + rndMin;
			cout << inputArr[i][j];
			if (j == (size - 1)) {
				cout << "]\n";
			}
			else {
				cout << "\t";
			}
		}
	}

	/* find result in area а */
	firstIteration = true;
	stop = size;
	for (int h = 0; h < size; h++) {
		start = h;		
		for (int w = start; w < stop; w++){
			if (firstIteration == true) {
				firstIteration = false;
				tempMax = inputArr[h][w];
			}
			else if (inputArr[h][w] > tempMax) {
				tempMax = inputArr[h][w];
			}
		}
		
	}

	outputArr[0] = tempMax;

	/* find result in area б */
	firstIteration = true;
	start = 0;
	for (int h = 0; h < size; h++) {
		stop = h+1;
		for (int w = start; w < stop; w++) {
			if (firstIteration == true) {
				firstIteration = false;
				tempMax = inputArr[h][w];
			}
			else if (inputArr[h][w] > tempMax) {
				tempMax = inputArr[h][w];
			}
		}
	}

	outputArr[1] = tempMax;

	/* find result in area в */
	firstIteration = true;
	for (int h = 0; h <= (size / 2); h++){
		start = h;
		stop = (size - h);
		for (int w = start; w < stop; w++) {
			if (firstIteration == true) {
				firstIteration = false;
				tempMax = inputArr[h][w];
			}
			else if (inputArr[h][w] > tempMax) {
				tempMax = inputArr[h][w];
			}
		}
	}
	
	outputArr[2] = tempMax;

	/* find result in area г */
	firstIteration = true;
	for (int h = size / 2; h < size; h++) {
		start = size-h-1;
		stop = h+1;
		for (int w = start; w < stop; w++) {
			if (firstIteration == true) {
				firstIteration = false;
				tempMax = inputArr[h][w];
			}
			else if (inputArr[h][w] > tempMax) {
				tempMax = inputArr[h][w];
			}
		}
	}
	
	outputArr[3] = tempMax;

	/* find result in area д */
	firstIteration = true;
	for (int h = 0; h < size; h++) {
		if (h < (size / 2)) {
			start = h;
			stop = size - h;
		}
		else {
			start =  size - h-1;
			stop = h+1;
		}
		for (int w = start; w < stop; w++) {
			if (firstIteration == true) {
				firstIteration = false;
				tempMax = inputArr[h][w];
			}
			else if (inputArr[h][w] > tempMax) {
				tempMax = inputArr[h][w];
			}
		}
	}
	
	outputArr[4] = tempMax;

	/*е!*/

	/* find result in area Ж */
	firstIteration = true;
	for (int h = 0; h < size; h++) {
		start =  0;		
		if (h < (size / 2)) {
			stop = h+1;
		}
		else {
			stop = size - h;
		}
		for (int w = start; w < stop; w++) {
			if (firstIteration == true) {
				firstIteration = false;
				tempMax = inputArr[h][w];
			}
			else if (inputArr[h][w] > tempMax) {
				tempMax = inputArr[h][w];
			}
		}
	}
	
	outputArr[6] = tempMax;

	/* find result in area з */
	firstIteration = true;
	stop = size;
	for (int h = 0; h < size; h++) {
		if (h < (size / 2)) {
			start = size - h-1;
		}
		else {
			start = h;
		}
		for (int w = start; w < stop; w++) {
			if (firstIteration == true) {
				firstIteration = false;
				tempMax = inputArr[h][w];
			}
			else if (inputArr[h][w] > tempMax) {
				tempMax = inputArr[h][w];
			}
		}
	}
	
	outputArr[7] = tempMax;

	/* find result in area и */
	firstIteration = true;
	stop = size;
	for (int h = 0; h < size; h++) {
		start = size - h - 1;
		for (int w = start; w < stop; w++) {
			if (firstIteration == true) {
				firstIteration = false;
				tempMax = inputArr[h][w];
			}
			else if (inputArr[h][w] > tempMax) {
				tempMax = inputArr[h][w];
			}
		}
	}
	
	outputArr[8] = tempMax;
	
	/* find result in area к */
	firstIteration = true;
	start = 0;
	for (int h = 0; h < size; h++) {
		stop = size - h;
		for (int w = start; w < stop; w++) {
			if (firstIteration == true) {
				firstIteration = false;
				tempMax = inputArr[h][w];
			}
			else if (inputArr[h][w] > tempMax) {
				tempMax = inputArr[h][w];
			}
		}
	}
	
	outputArr[9] = tempMax;

	/*Printing results*/
	for (int i = 0; i < outputArrSize; i++) {
		sprintf_s(output, "\nМаксимум в области %c = %i\n", outputArrKeys[i], outputArr[i]);
		cout << output;
	}
}