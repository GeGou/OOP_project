#include <iostream>
#include <vector>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Entrance::Entrance(int nsegs, int cur_seg, int k) {
    // cout << "Entrance construction." << endl;
    string temp = "Entrance_";
    this->id = temp.append(to_string(cur_seg));      // making the toll unique
    int temp0 = rand() % 3 + 1;       // random employee tolls 1-3
    for (int i = 0; i < temp0; i++) {
        this->tolls.push_back(new Toll(nsegs, cur_seg, k));
    }
    temp0 = rand() % 5 + 1;       // random e-tolls 1-5
    for (int i = 0; i < temp0; i++) {
        this->e_tolls.push_back(new Toll(nsegs, cur_seg, 2*k));
    }
}

Entrance::~Entrance() {
    cout << "Entrance destruction." << endl;
    // this->tolls.~vector();
    // this->tolls.clear();
    // this->e_tolls.clear();
}

void Entrance::operate() {

}