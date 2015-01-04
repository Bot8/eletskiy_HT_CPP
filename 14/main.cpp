#include <iostream>
#include <string.h>

using namespace std;
/*
    swap a and b arguments
 */
void swap(int * a, int * b){
    int * temp;
    temp = a;
    a = b;
    b = temp;
}

/*
    cut from inputString piace begining in m index endin in m index of inputString and return cuted peace
 */
char * cutStringPiace (int m, int n, const char * const inputString){

    int  cutedPiaceSize = n - m;
    char * cutedPiace = new char [cutedPiaceSize];

    strncpy(cutedPiace, inputString+m, cutedPiaceSize);
    cutedPiace[cutedPiaceSize] = NULL;

    return cutedPiace;
}
/*
    cut from inputString piace begining in m index endin in m index of inputString and return cuted string
 */
char * cutPiaceFromString (int m, int n, const char * const inputString){

    int filled = strlen(inputString);
    int cutedPiaceSize = m + filled - n;

    char * cutedString = new char [cutedPiaceSize];

    strncpy(cutedString, inputString, m);
    strcat(cutedString, inputString+n);

    return cutedString;
}
/*
    find all matches inputChar in inputString
 */
void findAllMatches(char inputChar, const char * const inputString){
    int filled = strlen(inputString);
    int matches = 0;
    for(int i = 0; i<filled; i++){
        if(inputString[i]==inputChar){
            matches++;
            cout << "[" <<  inputString[i] << "," << i+1 << "]" << endl;
        }
    }
    if(matches==0){
        cout << "No matches" << endl;
    }
}
/*
    find last match inputChar in inputString
 */
void findLastMatch(char inputChar, const char * const inputString){
    int filled = strlen(inputString);
    int matches = 0;
    for(int i = filled; i>0; i--){
        if(inputString[i]==inputChar){
            matches++;
            cout  << "[" <<  inputString[i] << "," << i+1 << "]" << endl;
            break;
        }
    }
    if(matches==0){
        cout << "No matches" << endl;
    }
}

int main() {

    const int length = 255;
    char inputString[length];
    int free, filled;
    int m, n;
    char inputChar;

    cout << "Enter string: " << endl;

    gets(inputString);


    filled = strlen(inputString);
    free = length - filled;

    cout << "Filled: " << filled << endl;
    cout << "Free: " << free << endl;

    cout << "Enter begin index: ";
    cin >> m;
    cout << "Enter end index: ";
    cin >> n;

    if(m>n){
        swap(m, n);
    }

    n++;

    char * cutedPiace;
    cutedPiace = cutStringPiace(m, n, inputString);
    cout << "Cuted piace: " << cutedPiace << endl;
    delete [] cutedPiace;

    char * cutedString;
    cutedString = cutPiaceFromString(m, n, inputString);
    cout << "Cuted string: " <<cutedString << endl;
    delete [] cutedString;

    cout << "Enter search char: ";

    cin >> inputChar;

    cout << "All macthes [" << inputChar << "] in input string" << endl;

    findAllMatches(inputChar, inputString);

    cout << "Last macth [" << inputChar << "] in input string" << endl;

    findLastMatch(inputChar, inputString);

    return 0;
}