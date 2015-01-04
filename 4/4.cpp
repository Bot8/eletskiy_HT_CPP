#include <iostream>
using namespace std;
void main() {
	char output[255], reverce[255], suffix[10];
	sprintf(reverce, "");
	int number, count = 0, sum = 0, digit;
	cout << "Enter a number: ";
	cin >> number;
	if (number < 0) {
		number *= -1;
		sprintf(suffix, "-");
	} else {
		sprintf(suffix, "");
	}
	do {
		count++;
		digit = number % 10;
		sum += digit;
		sprintf(reverce, "%s%i", reverce, digit);
		number /= 10;
	} while (number > 0);

	sprintf(output, " cout = %i \n sum = %i \n reverce = %s%s \n", count, sum, reverce, suffix);
	
	cout << output;
}