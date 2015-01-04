#include <iostream>

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
void fillArray(T arInput[], int arSize) {
    for (int i = 0; i < arSize; i++) {
        arInput[i] = i+1;
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
	shuffeling array
*/
template <typename T>
T shuffle(T array[], int size) {
    for(int i = 0; i<size; i++) {
        changeVals(array, i, random(0, size-1));
    }
}
/*
	searchig first occurrence  search in array
*/
template <typename T>
int search(T array[], int size, T search){
    for (int i = 0; i<size; i++) {
        if(search == array[i]) {
            return i;
        }
    }
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
        stop = size;
    }

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

int main() {
    srand(time(NULL));
    const int arSize = 20;
    int arr[arSize];
    int min = 1, max = 20;
    int randomValue = random(min, max);

    fillArray(arr, arSize);
    cout << endl << "Normal array ";
    printArray(arr, arSize);

    shuffle(arr, arSize);
    cout << endl << "shuffled array ";
    printArray(arr, arSize);

    cout << "Random value from array: " << randomValue << endl;

    int rndValPos = search(arr, arSize, randomValue);

    cout << "Random value posiztion in array: " << rndValPos << endl;

    arrSortSelection(arr, arSize, 1, 0, rndValPos);

    arrSortSelection(arr, arSize, 0, rndValPos+1, arSize);

    cout << endl << "sorted array ";
    printArray(arr, arSize);

    return 0;
}