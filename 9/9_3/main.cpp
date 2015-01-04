#include <iostream>
#include <cmath>

using namespace std;
template <typename T> T round(T input, int accuracy){
    float factor = pow(10, accuracy);
    T output = (T)(int)(input*factor)/factor;
    return output;
}
int main() {
    double input;
    int accuracy;
    cout << "Enter value to round: ";
    cin >> input;
    cout << endl;
    cout << "Enter accuracy: ";
    cin >> accuracy;
    cout << endl << "Round result = " << round(input, accuracy) << endl;
    return 0;
}