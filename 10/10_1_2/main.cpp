#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

/*
	generate random value
*/

template<typename T>
T random(T start, T stop) {
    return rand() % (start-stop) + start;
}
/*
	filling array with random values
*/
template<typename T>
void fillArray(T arInput[], int arSize, T start, T stop) {
    for (int i = 0; i < arSize; i++) {
        arInput[i] = random(start, stop);
    }
}
/*
	print array
*/
template <typename T>
void printArray(T arInput[], int arSize) {
    cout << endl << "[";
    for (int i = 0; i < arSize; i++) {
        cout << arInput[i];
        if (i != (arSize - 1)) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}
/*
	swap 2 vals in array
*/
template <typename T>
T changeVals (T array[], int i, int j){
    T temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}
/*
	check need of swapping  considering sort direction
	(
	    direction = 1 sort  1-2-3
	    direction !=1 sort  3-2-1
	)
*/
template <typename T>
bool checkDirection(T x, T y, int direction) {
    bool change = false;
    if(direction == 1 ){
        if (x > y) {
            change = true;
        }
    } else {
        if (x < y) {
            change = true;
        }
    }
    return change;
}
/*
	sort array from position start to position stop considering sort direction
*/
template<typename T>
void arrSortSelection(T array[], int size, int direction = 1, int start = 0, int stop = 0) {
    int point;
    bool change;
    if(stop == 0) {
        stop = size; // sort array till the end
    }
    /*
        sort
     */
    for (int i = start; i < stop-1; i++) {
        point = i;
        T pointer = array[i];
        for (int j = i + 1; j < stop; j++) {

            change = checkDirection(array[j], pointer, direction);

            if(change){
                pointer = array[j];
                point = j;
            }

        }
        if (point != i) {
            changeVals(array, point, i);
        }
    }
}

template <typename T>
bool sortExtreem(T array[], int size){
    T min;
    int leftIndex, rightIndex;
    leftIndex = rightIndex = 0;
    min = array[0];
    for (int i = 1; i<size; i++) {
        if(array[i]<min) {
            leftIndex = i; // left index of minimal element
            min = array[i];
        }
        if(array[i]==min){
            rightIndex = i; // right index of minimal element
        }
    }
    if(leftIndex < rightIndex) {
        cout << endl << "Minimal value = "<< min <<endl;
        cout << endl << "Sorting from "<<leftIndex<< " index to " << rightIndex<< " index. "<<endl;
        /*
         sort array from left index of minimal element  to right index of minimal element
         */
        arrSortSelection(array, size, 0, leftIndex, rightIndex);
        return true;
    } else {
        return false;
    }
}

int main() {
    srand(time(NULL));
    const int arSize = 20;
    int array[arSize] = {};
    int start = -20, stop = 20;

    fillArray(array, arSize, start, stop);
    cout << endl << "normal array";
    printArray(array, arSize);

   if( sortExtreem(array, arSize)){
       cout << endl << "Sorted array";
       printArray(array, arSize);
   } else {
       cout << endl << "Array dont sorted because we have no area to sort (minimal value is unic)";
   }


    return 0;
}