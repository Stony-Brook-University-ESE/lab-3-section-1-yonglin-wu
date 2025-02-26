#ifndef LIST_H
#define LIST_H

#include <string>
using namespace std;

class node {
    public:
        string name;
        string author;
        int year;
        node *next; //pointer to next entry

        node(string na, string a, int y, node* n = nullptr) {
            next = n;
            name = na;
            author = a;
            year = y;
        }

        friend class list;
};

class list{
    private:
        node* head;
    public:
        list(); //constructor
        ~list(); //destructor

        bool empty() const;
        const string& front() const;
        void addSong(string data1, string data2, int data3);
        void removeSong(string name);
        void displayAll();
        void deleteThree(string name1, string name2, string name3);
};

#endif
