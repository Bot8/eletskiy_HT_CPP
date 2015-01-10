#include <iostream>

using namespace std;

/*
    value setter
 */

int enterValue(char name[]){
    int value;
    cout<< endl << "Enter value " << name << ": ";
    cin >> value;
    cout << endl;
    return value;
}

/*
    sum calculator by pointers for pointers
    set to first argumet sum of secont end fird arguments
 */

void sum(int **ppa, int **ppb, int **ppc){
    ** ppc =  **ppa + **ppb;
}

/*
    factorial calculator
 */

void factorial(int * p){
    int n = *p;
    while(n>0){
        n--;
        *p += n;
    }
}

/*
    pow first argument to the second argument degree
*/

void pow(int * p, int degree){
    if(degree == 0) {
        *p = 0;
    } else {
        int multiplyer = *p;
        while(degree>1){
            degree--;
            *p *= multiplyer;
        }
    }
}

/*
    simple calculator functions
    sum, sub, mult (multiply), divide
 */

template <typename T>
void calcSum(T *a, T *b, T *c){
    *c = *a + *b;
}

template <typename T>
void calcSub(T *a, T *b, T *c){
    *c = *a - *b;
}

template <typename T>
void calcMult(T *a, T *b, T *c){
    *c = *a * *b;
}

template <typename T>
void calcDivide(T *a, T * b, T * c){
    *c = *a / *b;
}

/*
    simple calculator functions linking
 */

enum Operators { cSum = '+', cSub = '-', cMult = '*', cDivide = '/'};

/*
    simple calculator
    get action char,
    ling to first, second arguments and result
    process action to first and second argument
    write to fird argument
 */

template <typename T>
void calculate(char action, T * a, T * b, T * c){

    void (*function)(T * a, T * b, T * c);
    switch(action){
        case cSum:
            function = &calcSum;
            break;
        case cSub:
            function = &calcSub;
            break;
        case cMult:
            function = &calcMult;
            break;
        case cDivide:
            function = &calcDivide;
            break;
        default:
            cout << endl << "No calc action" << endl;
            return;
    }
    function(a,  b,  c);
}

int main() {

    int a, b, c;
    int degree;
    int *pa = &a, *pb = &b, *pc = &c;
    int **ppa = &pa, **ppb = &pb, **ppc = &pc;

    a = enterValue({"a"});
    b = enterValue({"b"});

    char operation;
    cout<< "Enter operator: ";
    cin >> operation;

    calculate(operation, pa, pb, pc);

    cout << "c = " << c << endl;

    sum (ppa, ppb, ppc);
    cout << "operating with pointer to pointer a+b = " << c << endl;

    degree = enterValue({"degree of b"});
    pow(pb, degree);
    cout << "b^" << degree << "= "<<b<<endl;

    factorial(pa);
    cout << "a! = " << a << endl;

    return 0;
}
