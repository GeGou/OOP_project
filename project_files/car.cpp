#include <iostream>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Car::Car(int cur_seg, int nsegs) {
    cout << "Car construction." << endl;
    this->exit_node = rand() % nsegs + cur_seg;       // isws 8elei cur_Seg+1
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