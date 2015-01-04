#include <iostream>
#include <ctime>

using namespace std;

/*
	generate random value
*/

template <typename T>
T random(T min, T max){
    return rand()%(max-min)+min;
}

/*
	print array
*/

template <typename T>
void printArray(T *arr, int size){
    cout<<endl<<"[";
    for(int i = 0; i<size; i++){
        cout<<arr[i];
        if(i!=size-1){
            cout<<",";
        }
    }
    cout<<"]";
}

/*
	filling array with random values
*/

template <typename T>
void fillArray(T *arr, int size, T min, T max){
    for(int i = 0; i<size; i++) {
        *(arr+i) = random(min, max);
    }
}

/*
	swaping odd and even values in array
*/

template <typename T>
void swapArray(T *arr, int size){
    for(int i=0; i<size-1; i+=2){
        T temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }
}

int main() {
    srand(time(NULL));
    const int size = 10;
    int array[size];
    int min = 0, max = 9;

    fillArray(array, size, min, max);
    cout <<endl<< "Normal array ";
    printArray(array, size);
    swapArray(array, size);
    cout <<endl<< "Swapped array ";
    printArray(array, size);
    return 0;
}