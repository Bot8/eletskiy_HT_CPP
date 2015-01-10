#include <iostream>
#include <ctime>
using namespace std;
/*
    print player name
 */
void playerName(int i) {
    switch (i) {
        case 0:
            cout << "human";
            break;
        case 1:
            cout << "PC";
            break;
        }
}
/*
    print cube edge
 */
void cubeEdge(int edge){
    bool dot = false;
    for (int y = 0; y<3; y++){
        for(int x = 0; x < 5; x++) {
            dot = false;
            switch(edge){
                case 1:
                    if(x==2 && y==1) {
                        dot = true;
                    }
                    break;
                case 2:
                    if((x==4 && y==0) || (x==0 && y==2)) {
                        dot = true;
                    }
                    break;
                case 3:
                    if((x==4 && y==0) || (x==0 && y==2) || (x==2 && y==1)) {
                        dot = true;
                    }
                    break;
                case 4:
                    if((x<1 || x>3) && y!=1) {
                        dot = true;
                    }
                    break;
                case 5:
                    if(((x<1 || x>3) && y!=1) || (x==2 && y==1)) {
                        dot = true;
                    }
                    break;
                case 6:
                    if((x%2==0) && (y%2==0)) {
                        dot = true;
                    }
                    break;
            }
            if(dot) {
                cout << 0;
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}
 /*
    fall of one cube
    return random num and print edge
 */
int cubeFall() {
    int edge = rand() % 6 + 1;
    cubeEdge(edge);
    return edge;
}
/*
    Trow cubes
    return sum of cubes
 */
int cubesThrow(int cubes){
    int sum = 0;
    for (int i = 0; i < cubes; i++) {
        sum += cubeFall();
    }
    cout << endl;
    return sum;
}
int main(){
    /*
        modify random
     */
	srand(time(NULL));
    /*
        players - num of players
        cubes - num of cubes
        attempts - num of attempts
        results[player]{player, total sum, average}
        firstThrow - who will make first throw
        win{player, sum}
        draw - draw identificator
     */
	const int players = 2;
	int cubes = 2, attempts = 5;
	int results[players][3] = {0};
    int firstThrow = rand()%2;
    int win[2] = {0};
    bool draw = false;

    /*
        shuffle players throw
    */
    if(firstThrow==1) {
        results[0][0] = 1;
    } else {
        results[1][0] = 1;
    }

    /*
        making trows
     */

	for (int i = 0; i < attempts; i++){
		for (int j = 0; j < players; j++) {
            playerName(results[j][0]);
            cout << " throw " << i+1 <<endl;
			results[j][1] += cubesThrow(cubes);
		}
	}
	/*
	    calculate average
	 */
	for (int j = 0; j < players; j++) {
		results[j][2] = results[j][1] / attempts;
	}

    /*
        printing results and looking for max result
     */

	for (int i = 0; i < players; i++) {
        playerName(results[i][0]);
		cout << " result " << results[i][1] << " avg " << results[i][2] << endl;
        if((i==0) || (results[i][1]>win[1])) {
            win[0]= results[i][0];
            win[1]= results[i][1];
            draw = false;
        } else if(results[i][1]==win[1]) {
            draw = true;
        }
	}

    /*
        printing result of the game
     */

    if(draw) {
        cout << "DRAW!"<< endl;
    } else {
        playerName(win[0]);
        cout << " WIN!"<< endl;
    }
	return 0;
}