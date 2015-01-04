#include <iostream>
#include <cmath>

using namespace std;

/*
    Printing a equation segment
    variable - value,
    first - flag if printing + before variable
    condition - flag of printing 1 (before x not print, alone prints)
 */

template <typename T>
bool printVar(T variable, bool first = false, bool condition = false) {
    bool result = false;
    if(variable!=0) {
        T absVariable = abs(variable);
        if (variable>=0 && !first) {
            cout << "+";
        }
        if (variable<0) {
            cout << "-";
        }
        if(variable!=1 || !condition) {
            cout << absVariable;
        }
        result = true;
    }
    /*
        if 0 skip
     */
    return result;
}

template <typename T1, typename T2>
double solveLinear(T1 a, T2 b){
    if(a==0){
        /*
            division by zero
         */
        cout << "Invalid a";
    } else {
        cout << "Solving linear"<< endl;
        double result = (double)(b*(-1))/a;
        if(printVar(a, true)) {
            cout << "x";
        }
        printVar(b);
        cout << "=0" << endl;
        cout << "x=" << result<< endl;
    }
}

template <typename T1, typename T2, typename T3>
void solveSquare(T1 a, T2 b, T3 c) {
    bool first = true;
    if(a==0) {
       if(b==0) {
           cout << "Invalid a and b";
       } else {
           /*
            it is linear
            */
           solveLinear(b,c);
       }
        return;
    }
    cout << "Solving square"<< endl;
    double d = b*b - 4 * a * c;

    if(printVar(a, first, true)){
        first = false;
        cout << "x^2";
    }

    if(printVar(b, first, true)) {
        cout << "x";
    }

    printVar(c);

    cout << "=0" << endl;

     if(d == 0) {
         cout << "x1=x2=" << ((-1)*b)/(2*a);
     } else if(d>0){
        d = sqrt(d);
        cout << "x1=" <<  ((-1)*b+d)/(2*a);
        cout << endl;
        cout << "x2=" <<  ((-1)*b-d)/(2*a);
     } else {
        cout << "No solutions";
     }

}

int main() {
    double a,b,c;
    cout << endl << "Lets solve linear equation like" << endl;
    cout << "ax+b=0"<<endl;
    cout << "Enter a: ";
    cin>> a;
    cout << "Enter b: ";
    cin>> b;
    cout << endl;
    solveLinear(a, b);
    cout << endl << "Lets solve linear equation like" << endl;
    cout << "ax^2+bx+c=0" << endl;
    cout << "Enter a: ";
    cin>> a;
    cout << "Enter b: ";
    cin>> b;
    cout << "Enter c: ";
    cin>> c;
    cout << endl;
    solveSquare(a, b, c);
    return 0;
}