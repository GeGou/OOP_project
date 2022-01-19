#include <iostream>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Car::Car(int nsegs, int cur_seg) {
    // cout << "Car construction." << endl;
    this->exit_node = rand() % (nsegs - cur_seg) + (cur_seg + 1);       // rand() % 30 + 1985; -> v3 range 1985-2014
    // cout << "exit node: " << exit_node << endl;
    this->segment = -1;
    this->is_ready = false;
}

Car::~Car() {
    cout << "Car destruction." << endl;
}

void Car::seg(int seg) {
    this->segment = seg;
}

void Car::ready() {
    this->is_ready = true;
}