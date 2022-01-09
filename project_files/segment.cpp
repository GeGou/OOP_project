#include <iostream>
#include <vector>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Segment::Segment(int index, int k, int percent) : entry(index, k) {
    cout << "Segment construction." << endl;
    cout << "Segment_" << index <<" - Give capacity in cars: ";
    cin >> this->capacity;      // user gives the capacity
    cout << "--------------------" << endl; 
    this->index = index;
    if (index == 0) {
        this->prev_segment = NULL;
    }
    vector<Car> cars;
    for (int i = 1; i <= 5; i++) {
        // Car new_car;
        // cars.push_back(new_car);
    }
}

Segment::~Segment() {
    cout << "Segment destruction." << endl;
}

void Segment::enter() {
    if (this->prev_segment == NULL) {
        // ENTOLES
    }
}

void Segment::exit() {
    if (this->next_segment == NULL) {
        // ENTOLES
    }
}

void Segment::pass() {

}

int Segment::get_no_of_vehicles() {
    return this->segment_cars;
}

void Segment::operate() {

}