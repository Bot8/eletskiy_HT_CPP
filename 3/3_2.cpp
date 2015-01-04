#include <iostream>
using namespace std;
void main() {
	char output[255];
	int first, second, temp, sum;
	cout << "Enter first digit: ";
	cin >> first;
	cout << "Enter first digit: ";
	cin >> second;
	if (first > second) {
		temp = first;
		first = second;
		second = temp;
	}
	sum = 0;
	for (int i = first; i <= second; i++) {
		if (i % 2 != 0) {
			sum += i;
		}
	}
	sprintf(output, "Sum of odd numbers between %i and %i = %i\n", first, second, sum);
	cout << output;

}