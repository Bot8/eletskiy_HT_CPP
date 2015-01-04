#include <iostream>

using namespace std;

/*
   printing array function
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
    filling array function
 */

template <typename T>
void fillArray(T *arr, int size, int multiplyer){
    for(int i = 0; i<size; i++) {
        *(arr+i) = i*multiplyer;
    }
}

/*
    filling result array remains the second array
 */

template <typename T>
void fillLast(T *fromArr, int from, int fromArrSize, T *toArr, int toArrPosition){

    for (int i = from, j = ++toArrPosition; i< fromArrSize; i++, j++){
        *(toArr+j) = *(fromArr+i);
    }
}

int main() {
    srand(time(NULL));
    const int aSize = 2;
    const int bSize = 4;
    int cSize = aSize+bSize;
    int aArr[aSize], bArr[bSize];
    int * cArr;

    cArr = new int [cSize];
    /*
        fill and print first and second arrays
     */
    fillArray(aArr, aSize, 2);
    fillArray(bArr, bSize, 3);
    cout <<endl<< "Array A";
    printArray(aArr, aSize);
    cout <<endl<< "Array B";
    printArray(bArr, bSize);

    /*
        iterate result array an filling it
        int a and int b - is pointer of first and second arrays
        int c - pointer of result array remains of the second array
     */

    for(int a = 0, b = 0, c = 0; c<cSize; c++){

        if(aArr[a]<bArr[b]){

            *(cArr+c) = aArr[a];
           a++;
           if(a == aSize){
               fillLast (bArr, b, bSize, cArr, c);
               break;
           }
        } else {
            *(cArr+c) = bArr[b];
           b++;
            if(b == bSize){
                fillLast (aArr, a, aSize, cArr, c);
                break;
            }
        }
    }
    /*
        print result array
     */
    cout <<endl<< "Result array";
    printArray(cArr, cSize);
    delete [] cArr;
    return 0;
}