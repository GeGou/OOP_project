#include <iostream>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Toll::Toll(int nsegs, int cur_seg) {
    // cout << "Toll construction." << endl; 
    for (int i = 0; i < 30 ; i++) {
        this->waiting_vehicles.push_back(new Vehicle(nsegs, cur_seg));
    }
}

Toll::~Toll() {
    cout << "Toll destruction." << endl;
    // this->vehicles.clear();

}

void Toll::add_vehicles(int nsegs, int cur_seg) {
    if (this->waiting_vehicles.size() < 30) {
        for (int i = 0; i < (30-this->waiting_vehicles.size()) ; i++) {
            this->waiting_vehicles.push_back(new Vehicle(nsegs, cur_seg));
        }   
    }
}

Vehicle* Toll::remove_vehicle() {
    // maybe is a wrong way to temporary store a vehicle object
    Vehicle* temp = this->waiting_vehicles[1];
    this->waiting_vehicles.erase(this->waiting_vehicles.begin());
    return temp;
}