#include <iostream>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Vehicle::Vehicle(int cur_seg) {
    // cout << "Vehicle construction." << endl;
    this->exit_node = rand() % (nsegs - cur_seg) + (cur_seg + 1);
    this->segment = -1;
    this->ready = false;
}

Vehicle::~Vehicle() {
    cout << "Vehicle destruction." << endl;
}

int Vehicle::get_exitnode() const {
    return this->exit_node;
}

void Vehicle::set_segment(int seg) {
    this->segment = seg;
}

void Vehicle::set_ready() {
    this->ready = true;
}

bool Vehicle::is_ready() const {
    return this->ready;
}

void Vehicle::print() const {
    cout << "Vehicle info -> Starting segment: " << this->segment
        << " / Exit node: " << this->exit_node
        << " / Ready: " << this->ready << endl;
}