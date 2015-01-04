#include <iostream>
using namespace std;
void main() {
	char output[255], delimitter[2];
	int count, lineType = 0;
	char sumbol[10];
	cout << "Enter line length: ";
	cin >> count;
	if (count < 1) {
		sprintf(output, "Nothing to output");
	} else {
		sprintf(output, "");
		sprintf(delimitter, "");
		cout << "Enter line type (0 - horizontal, 1 - vertical) [0]: ";
		cin >> lineType;
		cout << "Enter symbol: ";
		cin >> sumbol;
		if (lineType == 1){
			sprintf(delimitter, "\n");
		}		
		for (int i = 0; i <= count; i++) {
			sprintf(output, "%s%s%s", output, sumbol, delimitter);
		}
	}
	sprintf(output, "%s \n", output);
	cout << output;
}