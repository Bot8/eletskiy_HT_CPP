#include <cstdlib>
#include <iostream>

using namespace std;

char convertChar(int digit) {
    const int charsLength = 37;
    char chars[charsLength] = {
            '0', '1', '2', '3', '4',
            '5', '6', '7', '8', '9',
            'A', 'B', 'C', 'D', 'E',
            'F', 'G', 'H', 'I', 'J',
            'K', 'L', 'M', 'N', 'O',
            'P', 'Q', 'R', 'S', 'T',
            'U', 'V', 'W', 'X', 'Y',
            'Z'
    };
    return chars[digit];
}

void convert(int nmbr, int system) {

    int i, n = 1, temp = nmbr;
    /*
        found num of digits
    */
    while (temp >= system) {
        temp /= system;
        n++;
    }
    /*
        set result string
    */
    char * output = new char [n];

    i = n-1;
    /*
        writing converted result from the end of number
     */
    while(nmbr >= system){
        output[i] = convertChar(nmbr%system);
        nmbr /= system;
        i--;
    }
    /*
        write last digit
     */
    output[i] = convertChar(nmbr);
    /*
        print result
     */
    for (i = 0; i<n; i++) {
        cout<< output[i];
    }

}

int main() {
    int inputNum, system;

    cout << "Enter number: ";
    cin >> inputNum;

    cout << "\n" << "Enter system: ";

    cin >> system;

    if(system>1 && system < 37) {
        cout << "\n" << inputNum << " in " << system << " system, equals ";
        convert(inputNum, system);
        cout << "\n";
    } else {
        cout << "\n" << "Illegal system" << "\n";
    }

    return 0;
}