#include <iostream>

using namespace std;

struct s_time
{
    unsigned hours: 6;
    unsigned minutes: 6;
    unsigned seconds: 6;
};

/*
    prints time value with leading zero
 */
void printTimePart(unsigned part);

/*
    prints time formated like HH:MM:SS
 */
void showTime(s_time timeVar);

/*
    sets time to the s_time struct
    if variable 'current' true - sets current time
 */
s_time setTime(bool current = false, int timezone = 0);

int main(){
    s_time timeVal;
    timeVal = setTime(false);
    showTime(timeVal);
    timeVal = setTime(true, 3);
    showTime(timeVal);
    return 0;
}

void printTimePart(unsigned part){
    if(part<10) {
        cout << 0;
    }
    cout << part;
}

void showTime(s_time timeVar){
    cout << endl;
    printTimePart(timeVar.hours);
    cout << ":";
    printTimePart(timeVar.minutes);
    cout << ":";
    printTimePart(timeVar.seconds);
    cout << endl;
}

s_time setTime(bool current, int timezone){
    s_time timeVal;
    int a;
    if(!current) {
        cout << "Set hours: ";
        cin >> a;
        timeVal.hours = a;
        cout << endl;
        cout << "Set minutes: ";
        cin >> a;
        timeVal.minutes = a;
        cout << endl;
        cout << "Set seconds: ";
        cin >> a;
        timeVal.seconds = a;
        cout << endl;
    } else {
        a = time(NULL);
        a%=(60*60*24);
        timeVal.seconds = a%60;
        a/=60;
        timeVal.minutes = a%60;
        a/=60;
        a+=timezone;
        if(a<0){
            a*=-1;
        }
        timeVal.hours = a%24;
    }
    return timeVal;
}
