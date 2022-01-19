#include <iostream>
#include <vector>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Segment::Segment(int nsegs, int cur_seg, int k, int percent) : entrance(nsegs, cur_seg, k) {
    // cout << "Segment construction." << endl;
    cout << "Segment_" << cur_seg << " - Give capacity in cars: ";
    cin >> this->capacity;      // user gives the capacity
    cout << "------------------------------------" << endl; 
    this->cur_seg = cur_seg;
    if (cur_seg == 0) {
        this->prev_segment = NULL;
    }
    else if (cur_seg == nsegs - 1) {
        this->next_segment = NULL;
    }
    int temp = rand() % 30 + 10;     // starting cars are 10-40
    for (int i = 0 ; i < temp ; i++) {
        this->segment_cars.push_back(new Car(cur_seg, nsegs));
    }
}

Segment::~Segment() {
    cout << "Segment destruction." << endl;

}

void Segment::enter() {
    if (this->prev_segment == NULL) {
        // ENTOLES
    }
    this->entrance.operate();   // epiostrefei synolo oxhmatwn
}

void Segment::exit() {
    if (this->next_segment == NULL) {
        // ENTOLES
    }
    this->entrance.operate();
}

void Segment::pass() {

}

int Segment::get_no_of_vehicles() {
    return this->segment_cars.size();
}

void Segment::operate() {

}