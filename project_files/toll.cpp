#include <iostream>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Toll::Toll(int nsegs, int cur_seg, int k) {
    // cout << "Toll construction." << endl;
    this->k = k;
    int temp = rand() % 15;       // random cars waiting in toll / max 15 cars
    for (int i = 0; i < temp; i++) {
        this->cars.push_back(new Car(nsegs, cur_seg));
    }
}

Toll::~Toll() {
    cout << "Toll destruction." << endl;
    // this->cars.clear();
}

void Toll::add_cars(int cars) {
    
}

void Toll::remove_cars(int cars) {
    
}