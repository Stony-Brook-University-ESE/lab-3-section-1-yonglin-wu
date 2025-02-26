#include "list.h"
#include <iostream>
#include <string>
using namespace std;

// constructor
list::list() {
    head = nullptr;
}

// destructor
list::~list() {
    while (head != nullptr) {
        node *temp = head;
        head = head->next;
        delete temp;
    }
}

//check empty
bool list::empty() const {
    return head == nullptr;
}

//return front
const string& list::front() const {
    if (empty()) {
        cout << "List is empty" << endl;
    }
    return head->name;
}

// add a song alphabetically to the list
void list::addSongAlpha(string new_name, string new_county, int new_pop) {
    new_name[0] = toupper(new_name[0]); //captialize first letter of song name for formatting
    node* p = new node(new_name, new_county, new_pop); //create new node with input data
    node* p1, * p2;
    if (head == NULL) {
        head = p;
        p->next = NULL;
    }
    else {
        if (p->name < head->name) { // if new title is less than the current head
            p->next = head;
            head = p;
        }
        else {
            for (p1 = head, p2 = p1->next; p2 != NULL && p->name >= p2->name; p1 = p2, p2 = p2->next) ; 
            // search stops at the first node with a title 
            // greater than the current song or the last node of the list
            p1->next = p;
            p->next = p2;
        }
    }
}

// add a song by year of the list
void list::addSongYear(string new_name, string new_county, int new_pop) {
    node* p = new node(new_name, new_county, new_pop); //create new node with input data
    node* p1, * p2;
    if (head == NULL) {
        head = p;
        p->next = NULL;
    }
    else {
        if (p->year < head->year) { // if new title is less than the current head
            p->next = head;
            head = p;
        }
        else {
            for (p1 = head, p2 = p1->next; p2 != NULL && p->year >= p2->year; p1 = p2, p2 = p2->next) ; 
            // search stops at the first node with a title 
            // greater than the current song or the last node of the list
            p1->next = p;
            p->next = p2;
        }
    }
}

// remove a song from the front of the list
void list::removeSong(string name) {
    node* p, * p1, * p2;
    if (head == NULL) { // empty list
        cout << "Warning: list is empty" << endl;
        }
    else {
        if (name == head->name) { // if title is the inputted title
            p = head;
            head = head->next;
            delete p;
        }
        else {
            for (p1 = head, p2 = p1->next; p2 != NULL && name > p2->name; p1 = p2, p2 = p2->next) ; 
            // search stops when inputted argument is found or the end of the list is reached
            if (p2 != NULL && name == p2->name) {
                p1->next = p2->next;
                delete p2;
            }
            else
                cout << "Warning: the title is not in the list" << endl;
        }
    }
}

//method to print all songs
void list::displayAll(){
    cout << "Songs in the list alphabetically: " << endl;
    node* current = head;
    while (current != nullptr){
        cout << current->name << endl;
        current = current->next;
    }
}

void list::deleteThree(string name1, string name2, string name3){
    removeSong(name1);
    removeSong(name2);
    removeSong(name3);
}