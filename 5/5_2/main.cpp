#include <iostream>
using namespace std;
void main(){
	unsigned int width, height;
	bool dot;

	cout << "Enter width: ";
	cin >> width;
	if (width < 1) {
		cout << "Width is to little\n";
		return;
	}

	cout << "Enter height: ";
	cin >> height;
	if (height < 1) {
		cout << "Height is to little\n";
		return;
	}

	for (int j = 1; j <= width; j++) {
		cout << "*";
	}
	cout << "\n";

	if (height == 1)
		return;

	if (height > 2) {
		for (int i = 2; i < height; i++) {
			if (width > 1) {
				cout << "*";
				for (int j = 2; j < width; j++) {
					cout << " ";
				}
			}
			cout << "*\n";
		}
	}


	for (int j = 1; j <= width; j++) {
		cout << "*";
	}

	cout << "\n";

}