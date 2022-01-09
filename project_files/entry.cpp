#include <iostream>
#include <vector>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Entry::Entry(int i, int k) {
    cout << "Entry construction." << endl;
    string temp = "Entry_";
    this->id = temp.append(to_string(i));      // making the toll unique
    int temp0 = rand() % 3 + 1;       // random employee tolls
    for (int i = 0; i < temp0; i++) {
        Toll toll(i, k);
        this->tolls.push_back(toll);
    }
    int temp1 = rand() % 5 + 1;       // random e-tolls
    for (int i = 0; i < temp1; i++) {
        Toll toll(i, 2*k);
        this->e_tolls.push_back(toll);
    }
}

Entry::~Entry() {
    cout << "Entry destruction." << endl;
}

void Entry::operate() {

}