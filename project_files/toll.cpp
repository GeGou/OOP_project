#include <iostream>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Toll::Toll(int nsegs, int cur_seg) {
    // cout << "Toll construction." << endl; 
    for (int i = 0; i < 30 ; i++) {
        this->waiting_cars.push_back(new Car(nsegs, cur_seg));
    }
}

Toll::~Toll() {
    cout << "Toll destruction." << endl;
    // this->cars.clear();

}

void Toll::add_cars(int nsegs, int cur_seg) {
    if (this->waiting_cars.size() < 30) {
        for (int i = 0; i < (30-this->waiting_cars.size()) ; i++) {
            this->waiting_cars.push_back(new Car(nsegs, cur_seg));
        }   
    }
}

Car* Toll::remove_car() {
    // maybe is a wrong way to temporary store a car object
    Car* temp = this->waiting_cars[1];
    this->waiting_cars.erase(this->waiting_cars.begin());
    return temp;
}