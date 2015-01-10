#include <iostream>
using namespace std;
void main(){
	int monthStartsWith = 3;
	int daysInMonth = 31;
	int dayOfWeek = 1;
	cout << "Mo\tTu\tWe\tTh\tFr\tSa\tSu\n";
	for (int i = 1; i < monthStartsWith; i++){
		cout << " \t";
		dayOfWeek++;
	}
	for (int i = 1; i <= daysInMonth; i++) {
		cout << i <<"\t";
		dayOfWeek++;
		if (dayOfWeek > 7){
			cout << "\n";
			dayOfWeek = 1;
		}
	}
	cout << "\n";
}