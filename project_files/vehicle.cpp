#include <iostream>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Vehicle::Vehicle(int nsegs, int cur_seg) {
    // cout << "Vehicle construction." << endl;
    this->exit_node = rand() % (nsegs - cur_seg) + (cur_seg + 1);       // rand() % 30 + 1985; -> v3 range 1985-2014
    // cout << "exit node: " << exit_node << endl;
    this->segment = -1;
    this->ready = false;
}

Vehicle::~Vehicle() {
    cout << "Vehicle destruction." << endl;
}

int Vehicle::get_exitnode() {
    return this->exit_node;
}

void Vehicle::set_segment(int seg) {
    this->segment = seg;
}

void Vehicle::set_ready() {
    this->ready = true;
}

bool Vehicle::is_ready() {
    return this->ready;
}