#include <iostream>
#include <iomanip>
#include <string.h>
#include <cstdlib>

using namespace std;

/*
    States for user dialog when user adds row or collum
 */
enum State {CONTINUE, EXIT};
/*
    User actions in moving matrix
 */
enum Actions { mMoveUp = 'w', mMoveDown = 's', mMoveLeft = 'a', mMoveRight = 'd', mCancel = 'c', mDestroy = 'd'};

/*
    generate random value between strat and stop
 */
int random(int start, int stop);

/*
    initialize matrix and fill it with random values between strat and stop
 */

int ** initMatrix(int cols, int rows, int start, int stop);

/*
    print formated value
*/

void printVar(int var);

/*
    Print matrix
 */

void printMatrix(int **matrix, int cols, int rows);

/*
    Destroing matrix from memory
 */

void destroyMatrix(int **matrix, int rows);

/*
    add new row filled with 0, to the matrix, to the addTo position (numiration of rows starts with 1)
    modifying p_matrix and rows number
    row can be add to the begind, end or inside matrix
 */

bool addRow(int ***p_matrix, int * p_cols, int * p_rows, int addTo);

/*
    add new collum filled with 0, to the matrix, to the addTo position (numiration of collums starts with 1)
    modifying p_matrix and cols number
    colum can be added to the begin, end or inside the matrix
 */

bool addCol(int ***p_matrix, int * p_cols, int * p_rows, int addTo);

/*
    User dialog in console, to chose addRow or  addCol function and process it
 */

void userDialog(bool (*function)(int***, int*, int*, int), char * type, int ***p_matrix, int * p_cols, int * p_rows);

/*
    Move matrix up or down selected steps
    if steps > 0 matrix will be movied down
    if steps < 0 matrix will be movied up
    modifying p_matrix and rows number
 */

bool moveUpDown(int ***p_matrix, int * p_cols, int * p_rows, int steps);

/*
    Move matrix left or right selected steps
    if steps > 0 matrix will be to the right
    if steps < 0 matrix will be to the left
    modifying p_matrix and cols number
 */

bool moveLeftRight(int ***p_matrix, int * p_cols, int * p_rows, int steps);

/*
    User dialog in console, to chose moveUpDown or moveLeftRight function and process it
 */

void movieMatrix(int ***p_matrix, int * p_cols, int * p_rows);

int main() {

    /*
        set randomizer
    */
    srand(time(NULL));

    /*
        int start, stop - min and max values of new matrix;
    */
    int start = 10, stop = 99;

    /*
       int rows, cols number of rows and cols of new matrix
     */
    int rows = 5, cols = 5;

    /*
        userDialog variable to prints what user adding to matrix
     */
    char * type;

    int ** matrix;

    matrix = initMatrix(cols, rows, start, stop);

    /*
        print generated matrix;
     */
    printMatrix(matrix, cols, rows);

    /*
        userDialog to add row to the matrix (numiration of rows starts with 1)
    */

    strcpy(type, "row");
    userDialog(&addRow, type, &matrix, &cols, &rows);

    /*
        userDialog to add collum to the matrix (numiration of collums starts with 1)
    */

    strcpy(type, "col");
    userDialog(&addCol, type, &matrix, &cols, &rows);

    /*
        userDialog to move the matrix
    */

    movieMatrix(&matrix, &cols, &rows);

    /*
        End of program - destroying matrix
     */

    destroyMatrix(matrix, rows);

    return 0;
}

int random(int start, int stop){
    return rand()%(stop-start)+start;
}

void printVar(int var) {
    cout << setw(2) << var << " ";
}

int ** initMatrix(int cols, int rows, int start, int stop){
    int ** matrix = new int *[rows];
    for (int i = 0; i<rows; i++) {
        matrix[i] = new int[cols];
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = random(start, stop);
        }
    }
    return matrix;
}

void printMatrix(int **matrix, int cols, int rows){

    cout << setw(3) << " ";
    for (int i = 0; i < cols; i++) {
        /*
            print header of matrix (rows numbers) (numiration starts with 1)
         */
        printVar(i+1);
    }
    cout << endl;
    for(int i = 0; i<rows; i++) {
        /*
            print cols numbers (numiration starts with 1)
          */
        printVar(i+1);
        for(int j = 0; j<cols; j++){
            /*
                print matrix value
              */
            printVar(matrix[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

void destroyMatrix(int **matrix, int rows) {
    for (int i = 0; i<rows; i++) {
        /*
            destroy row
         */
        delete [] matrix[i];
    }
    /*
        destroy matrix
     */
    delete [] matrix;
}

bool addRow(int ***p_matrix, int * p_cols, int * p_rows, int addTo) {

    /*
        num of rows will be modifyed
     */
    int & l_rows = * p_rows;
    int cols = * p_cols;

    /*
        add to addTo-1 position, because printing numiration starts with 1
     */

    addTo--;

    if (addTo>l_rows || addTo<0) {
       /*
        out of matrix
       */
        return false;
    }

    /*
        incremet num of rows
    */

    l_rows++;

    int ** newMatrix = new int *[l_rows];

    for (int i = 0, j = 0; i<l_rows; i++) {

        if(addTo == i ) {
            /*
                new row in new position
            */
            newMatrix[i] = new int[cols];
            for(int n = 0; n<cols; n++) {
                /*
                    fill new row with 0
                 */
                newMatrix[i][n] = 0;
            }
        } else {
            /*
                old matrix row
             */
            newMatrix[i] = (*p_matrix)[j];
            j++;
        }
    }

    delete [] *p_matrix;

    *p_matrix = newMatrix;

    return true;
}

bool addCol(int ***p_matrix, int * p_cols, int * p_rows, int addTo) {

    int rows = * p_rows;
    /*
        num of cols will be modifyed
     */
    int & l_cols = * p_cols;

    /*
        add to addTo-1 position, because printing numiration starts with 1
    */

    addTo--;

    if (addTo>l_cols || addTo<0) {
        /*
            out of matrix
         */
        return false;
    }

    /*
        increment matrix cols
     */

    l_cols++;

    for (int i = 0; i<rows; i++) {

        int * temp = (*p_matrix)[i];
        (*p_matrix)[i] = new int[l_cols];
        for(int j = 0; j<l_cols; j++) {
            /*
                old collum value
             */
            (*p_matrix)[i][j] = (j<=addTo) ? temp[j] : temp[j-1];
        }
        /*
            new collum filled with 0
        */
        (*p_matrix)[i][addTo] = 0;

    }

    return true;
}

void userDialog(bool (*function)(int***, int*, int*, int), char * type,  int ***p_matrix, int * p_cols, int * p_rows){

    /*
        userWish user dialog value
        interRes - intermediate result of processed function
        newRowPosition -  position where user want to add new row or collum
    */

    char userWish;
    bool interRes;
    int newRowPosition;

    cout << "Wish you to add new "<<type<<"? [y/n]" << endl;

    cin >> userWish;

    State currentState = (userWish=='y' || userWish=='Y') ? CONTINUE : EXIT;

    while (currentState!=EXIT){

        cout << "Enter new "<<type<<" position: ";
        cin >> newRowPosition;
        interRes = (*function)(p_matrix, p_cols, p_rows, newRowPosition);
        if(interRes==false){
            /*
                adding row or collum failed
             */
            cout << endl << "Cannot process with entered value. Reenter? [y/n]"<<endl;

            cin>>userWish;

            if(userWish!='y' && userWish!='Y') {
                currentState = EXIT;
            }

        } else {
            /*
                adding row or collum success
             */
            currentState = EXIT;
            cout << "New matrix"<<endl;
            printMatrix(*p_matrix, *p_cols, *p_rows);
        }
    }
}

bool moveUpDown(int ***p_matrix, int * p_cols, int * p_rows, int steps) {

    /*
        num of rows will be modifyed
    */

    int & l_rows = * p_rows;
    int cols = * p_cols;

    /*
        icrement number of rows
     */

    l_rows += steps;

    int ** newMatrix = new int *[l_rows];

    for (int i = 0, j = (steps<0) ? steps*(-1) : 0; i<l_rows; i++) {

        if(i<steps){
            newMatrix[i] = new int[cols];
            for(int n = 0; n<cols; n++) {
                newMatrix[i][n] = 0;
            }
        } else {
            newMatrix[i] = (*p_matrix)[j];
            j++;
        }
    }

    delete [] *p_matrix;

    *p_matrix = newMatrix;

    return true;
}

bool moveLeftRight(int ***p_matrix, int * p_cols, int * p_rows, int steps) {

    /*
        num of cols will be modifyed
    */
    int rows = * p_rows;
    int & l_cols = * p_cols;

    l_cols+=steps;

    for (int i = 0; i<rows; i++) {
        int * temp = (*p_matrix)[i];
        (*p_matrix)[i] = new int[l_cols];
        for(int j = 0; j<l_cols; j++) {
            (*p_matrix)[i][j] = (j<steps) ? 0 : temp[j-steps];
        }
    }
    return true;
}

void movieMatrix(int ***p_matrix, int * p_cols, int * p_rows){
    /*
        action - user action value
        steps - how long wil be matrix movied
    */
    char action;
    int steps = 0;

    /*
        link to the function moveUpDown or moveLeftRight
    */

    bool (*function)(int ***p_matrix, int * p_cols, int * p_rows, int steps);

    while (action!=mCancel) {

        cout << "Enter direction ['w','a','s','d' to movie or 'c' to exit]:";

        cin >> action;

        if(action==mCancel) {
            break;
        }

        cout << "How many steps?:";

        cin >> steps;

        switch (action){
            case mMoveUp:
                if(steps>=*p_rows) {
                    /*
                        matrix height will be equals 0
                     */
                    cout << "This action will destroy matrix! Type 'd' to destroy end exit or 'r' to reenter action:";
                    cin >> action;
                    if(action==mDestroy){
                        return;
                    }
                    continue;
                }
                steps*=-1;
                function = moveUpDown;
                break;
            case mMoveDown:
                function = moveUpDown;
                break;
            case mMoveLeft:
                if(steps>=*p_cols) {
                    /*
                        matrix width will be equals 0
                     */
                    cout << "This action will destroy matrix! Type 'd' to destroy end exit or 'r' to reenter action:";
                    cin >> action;
                    if(action==mDestroy){
                        return;
                    }
                    continue;
                }
                steps*=-1;
                function = moveLeftRight;
                break;
            case mMoveRight:
                function = moveLeftRight;
                break;
            default:
                cout << "Wrong action '" << action << "'" << endl;
                continue;
        }
        function(p_matrix, p_cols, p_rows, steps);
        /*
            display modifyed matrix
         */
        printMatrix(*p_matrix, *p_cols, *p_rows);
    }
}
