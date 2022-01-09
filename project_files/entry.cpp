#include <iostream>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Entry::Entry(int i) {
    cout << "Entry construction." << endl;
    string temp = "Entry_";
    this->id = temp.append(to_string(i));      // making the toll unique
    this->tolls = rand() % 3 + 1;       // random employee tolls
    this->e_tolls = rand() % 5 + 1;     // random e-tolls
}

Entry::~Entry() {
    cout << "Entry destruction." << endl;
}

void Entry::operate() {

}