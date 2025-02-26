#include "list.h"
#include "list.cpp"
#include <iostream>
#include <string>
using namespace std;

int main(){
    list songs;

    string new_name;
    string new_author;
    int new_year;

    while(1){
        cout << "Enter song name: ";
        getline(cin, new_name);
        cout << "Enter author: ";
        getline(cin, new_author);
        cout << "Enter year: ";
        cin >> new_year;
        cin.ignore();
        songs.addSong(new_name, new_author, new_year);
        if (new_name == ""){
            cout << endl;
            break;
        }
    }

    songs.displayAll();

    string name1;
    string name2;
    string name3;

    cout << "Running function to remove three songs..." << endl;
    cout << "Enter first song name to remove: ";
    getline(cin, name1);
    cout << "Enter second song name to remove: ";
    getline(cin, name2);
    cout << "Enter third song name to remove: ";
    getline(cin, name3);
    cout << "Removing three songs..." << endl;

    songs.deleteThree(name1, name2, name3);

    songs.displayAll();

    return 0;
}