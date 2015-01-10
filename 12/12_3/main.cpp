#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

/*
    generate random value
*/
template <typename T>
T random(T min, T max){
    return rand()%(max-min)+min;
}

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
    cout<<"]"<<endl;
}

/*
    filling array function
 */

template <typename T>
void fillArray(T *arr, int size, T min, T max){
    for(int i = 0; i<size; i++) {
        *(arr+i) = random(min, max);
    }
}


/*
    searc val in array "arr"
*/
template <typename T>
bool inArray(T val, T * arr, int size){
    for(int i = 0; i<size; i++) {
        if(val==arr[i]){
            return true;
        }
    }
    return false;
}

/*
    writing values from aArr and bArr to new array arr
    return a pointer to the new array
    calculating new array size in variable "newSize";
*/

template <typename T>
T * implodeArrays(T * aArr, int aSize, T * bArr, int bSize,  T &newSize){

   newSize = aSize + bSize;
    T * arr = new T[newSize];
    int c = 0;
    for(int i =0;i<aSize;i++, c++){
        arr[c] = aArr[i];
    }
    for(int i =0;i<bSize;i++, c++){
        arr[c] = bArr[i];
    }
    return arr;
}

/*
    compare arrays mainArr and compareArr
    if flag diff set to true writing differences, else writin a simmilary values
    return new array "arr" with results, calculating new array size in variable "newSize"
 */
template <typename T>
T * arraysCompare(T * mainArr, int mainSize, T * compareArr, int compareSize,  T &newSize, bool diff = false){

    T * tempArr = new T[mainSize];

    int n = 0;

    for(int i = 0;i<mainSize;i++){
        bool compare = inArray(mainArr[i], compareArr, compareSize);
        if(compare != diff) {
            if(inArray(mainArr[i], tempArr, n)){
                continue;
            }
            tempArr[n] = mainArr[i];
            n++;
        }
    }
    newSize = n;
    T * arr = new T[n];
    for(int i = 0; i< n; i++) {
        arr[i] = tempArr[i];
    }
    delete [] tempArr;
    return arr;
}

int main() {
    /*
        aArr - A arr
        bArr - B arr

        min and max - area of random

        implodeArr - contains all values from A and B
        abSimilarArrSize - contains values what contains in A and B
        abDiffArrSize - contains values what contains in A and not contains in B
        baDiffArrSize - contains values what contains in B and not contains in A
        abUnicsArrSize - contains values what is not similar in A and B

     */
    srand(time(NULL));
    const int aSize = 5;
    const int bSize = 7;
    int min = 10, max = 20;

    int aArr[aSize], bArr[bSize];

    int *implodeArr;
    int implodeArrSize;

    int *abSimilarArr;
    int abSimilarArrSize;

    int *abDiffArr;
    int abDiffArrSize;

    int *baDiffArr;
    int baDiffArrSize;

    int *abUnicsArr;
    int abUnicsArrSize;

    /*
        fill and print first and second arrays
     */

    fillArray(aArr, aSize, min, max);
    fillArray(bArr, bSize, min, max);

    cout << endl << "Array A ";
    printArray(aArr, aSize);

    cout << endl << "Array B ";
    printArray(bArr, bSize);

    implodeArr = implodeArrays(aArr, aSize, bArr, bSize, implodeArrSize);

    cout << endl << "Implode A and B";
    printArray(implodeArr, implodeArrSize);

    abSimilarArr = arraysCompare(aArr, aSize, bArr, bSize, abSimilarArrSize);

    cout << endl << "Get simmilar values from A and B";
    printArray(abSimilarArr, abSimilarArrSize);

    abDiffArr = arraysCompare(aArr, aSize, bArr, bSize, abDiffArrSize, true);

    cout << endl << "Get A unic values";
    printArray(abDiffArr, abDiffArrSize);

    baDiffArr = arraysCompare(bArr, bSize, aArr, aSize, baDiffArrSize, true);

    cout << endl << "Get B unic values";
    printArray(baDiffArr, baDiffArrSize);

    cout << endl << "Get A and B unic values";
    abUnicsArr = implodeArrays(abDiffArr, abDiffArrSize, baDiffArr, baDiffArrSize, abUnicsArrSize);
    printArray(abUnicsArr, abUnicsArrSize);

    return 0;
}
