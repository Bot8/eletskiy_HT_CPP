#include <iostream>
#include <string.h>

using namespace std;

enum userActions {CONTINUE = 99, EXIT = 101, YES = 121, NO = 110};
enum searchBy {NAME = 1, GENRE, DIRECTEDBY, BESTINGENRE};

struct films {
    char  name[255];        // Название фильма
    char  directedBy[255];  // Режиссер
    char  genre[255];       // Жанр
    int   rating;           // Рейтинг популярности
    float price;            // Цена диска
};

/*
    print current film
 */
void printFilm(films & film);

/*
    print all films in shop
 */
void printShop(int shopSize, films * const shop);

/*
    destroyng shop array
 */

void destroyShop(int shopSize, films * shop);

/*
    add new film to shop array
    modifying shopSize and shop array
 */

void addFilm(int & shopSize, films ** shop);

/*
    seaching film in shop array
 */

void search(int shopSize, films * const shop, int method);

int main() {

    int shopSize = 3;
    char userAction;
    films * shop = new films[shopSize];
    int userSearch;

    /*
        fill shop array with test data
    */

    strcpy(shop[0].name, "Film1");
    strcpy(shop[0].directedBy, "Director2");
    strcpy(shop[0].genre, "Genre1");
    shop[0].rating = 5;
    shop[0].price = 510.5;

    strcpy(shop[1].name, "Film2");
    strcpy(shop[1].directedBy, "Director1");
    strcpy(shop[1].genre, "Genre1");
    shop[1].rating = 3;
    shop[1].price = 150.5;

    strcpy(shop[2].name, "Film3");
    strcpy(shop[2].directedBy, "Director2");
    strcpy(shop[2].genre, "Genre2");
    shop[2].rating = 2;
    shop[2].price = 520.5;

    cout << "Want you to add new film? [y/n] ";
    cin >> userAction;

    while(((int)userAction)==YES) {
        addFilm(shopSize, &shop);
        cout << "Want you to add one more film? [y/n] ";
        cin >> userAction;
    }

    do {

        cout << endl;

        cout << "Chose search method:"          << endl;
        cout << "1 - seach by film name"        << endl;
        cout << "2 - seach by film genre"       << endl;
        cout << "3 - seach by film director"    << endl;
        cout << "4 - seach best in genre"       << endl;

        cin >> userSearch;

        search(shopSize, shop, userSearch);

        cout << endl << "Want you to repeat search? [y/n] ";
        cin >> userAction;

    } while (((int)userAction)==YES);

    cout << "Want you to view all shop? [y/n] ";
    cin >> userAction;

    if(((int)userAction)==YES) {
        printShop(shopSize, shop);
    }

    destroyShop(shopSize, shop);

    return 0;
}

void printFilm(films & film) {
    cout << endl;
    cout << "Film name\t" << film.name << endl;
    cout << "Directed by\t" << film.directedBy << endl;
    cout << "Renre\t\t" << film.genre << endl;
    cout << "Rating\t\t" << film.rating << endl;
    cout << "Price\t\t" << film.price << endl;
    cout << endl;
}

void printShop(int shopSize, films * const shop) {
    for (int i = 0; i < shopSize; i++){
        printFilm(shop[i]);
    }
}

void destroyShop(int shopSize, films * shop) {
    delete [] shop;
}

void addFilm(int & shopSize, films ** shop) {

    int index, oldShopSize;

    index = oldShopSize = shopSize;

    shopSize++;

    /*
        make new array
    */

    films * newShop = new films[shopSize];

    /*
        copying existing films to the new array
    */

    for(int i = 0; i< oldShopSize; i++) {
        newShop[i] = (*shop)[i];
    }

    /*
        entering new film data
     */

    cout << endl << "Enter film name: ";
    cin >> newShop[index].name;

    cout << endl << "Enter directed by: ";
    cin >>newShop[index].directedBy;

    cout << endl << "Enter grenre: ";
    cin >> newShop[index].genre;

    cout << endl << "Enter rating: ";
    cin >> newShop[index].rating;

    cout << endl << "Enter price: ";
    cin >> newShop[index].price;

    cout << endl;

    /*
        delete ld shop
    */

    delete [] *shop;

    /*
        change pointer to the new shop
     */

    *shop = newShop;

}

void search(int shopSize, films * const shop, int method) {
    /*
        what we searching
    */
    char searchField[255];
    /*
        in what fileld we searching
    */
    char searchBy[255];
    /*
       with what we comparing
    */
    char compareWith[255];
    /*
        num of compares (not used in searching best in genre)
    */
    int compares = 0;
    /*
        used in searching best in genre
        foundIndex - index of best film
    */
    int foundIndex = -1;
    int maxRaiting = -1;
    switch(method){
        case NAME:
            strcpy(searchBy, "name");
            break;
        case DIRECTEDBY:
            strcpy(searchBy, "director");
            break;
        case BESTINGENRE:
        case GENRE:
            strcpy(searchBy, "genre");
            break;
        default:
            cout << "Search method not found";
            break;
    }

    cout << endl << "Enter film " << searchBy <<" : ";
    cin >>  searchField;

    cout << endl << "Search results: " << endl;

    for(int i = 0; i < shopSize; i++) {
        switch(method){
            case NAME:
                strcpy(compareWith, shop[i].name);
                break;
            case DIRECTEDBY:
                strcpy(compareWith, shop[i].directedBy);
                break;
            case GENRE:
            case BESTINGENRE:
                strcpy(compareWith, shop[i].genre);
                break;
        }
        if(0==strcmp(searchField, compareWith)) {
            if(method == BESTINGENRE){
                if(shop[i].rating>maxRaiting) {
                    foundIndex = i;
                    maxRaiting = shop[i].rating;
                }
            } else {
                compares++;
                printFilm(shop[i]);
            }
        }
    }

    cout << endl;

    if(compares<=0 && foundIndex<0){
        cout << "Nothing found";
    } else if(foundIndex>=0) {
        printFilm(shop[foundIndex]);
    } else {
        cout << compares << " found";
    }

    cout << endl;

}