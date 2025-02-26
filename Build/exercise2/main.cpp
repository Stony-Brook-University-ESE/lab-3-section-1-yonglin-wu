#include "list.h"
#include "list.cpp"
#include <iostream>
#include <string>
using namespace std;

int main(){
    list songs1;
    list songs2;

    string new_name;
    string new_author;
    int new_year;

    //prompt user to enter song name, author, and year until they enter an empty string
    while(1){
        cout << "Enter song name: ";
        getline(cin, new_name);
        cout << "Enter author: ";
        getline(cin, new_author);
        cout << "Enter year: ";
        cin >> new_year;
        cin.ignore();
        songs1.addSongAlpha(new_name, new_author, new_year);
        songs2.addSongYear(new_name, new_author, new_year);
        if (new_name == ""){
            cout << endl;
            break;
        }
    }

    // display all songs in the alphabetical list and the list by year
    songs1.displayAll();
    songs2.displayAll();

    string name1;
    string name2;
    string name3;

    //prompt user for three songs to remove from the list
    cout << "Running function to remove three songs..." << endl;
    cout << "Enter first song name to remove: ";
    getline(cin, name1);
    cout << "Enter second song name to remove: ";
    getline(cin, name2);
    cout << "Enter third song name to remove: ";
    getline(cin, name3);
    cout << "Removing three songs..." << endl;

    songs1.deleteThree(name1, name2, name3);
    songs2.deleteThree(name1, name2, name3);

    songs1.displayAll();
    songs2.displayAll();
    
    return 0;
}