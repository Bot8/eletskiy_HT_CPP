#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T> double average(T array[], int size){
    double sum = 0;
    for (int i = 0; i<size; i++) {
        sum += array[i];
    }
    return (sum)/size;
}

int main() {
    const int size = 3;
    int array[size];
    int start = 0, stop = 9;

    srand(time(NULL));

    for(int i = 0; i < size; i++) {
        array[i] = rand()%stop + start;
        cout << array[i]<<endl;
    }
    cout << endl << "Average " << average(array, size) << endl;
    return 0;
}