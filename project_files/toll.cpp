#include <iostream>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Toll::Toll(int cur_seg) : cur_seg(cur_seg) {
    // cout << "Toll construction." << endl; 
    this->waiting_v = rand() % 10 + 5;  // waiting vehicles 5-15
    for (int i = 0 ; i < this->waiting_v ; i++) {
        this->waiting_vehicles.push_back(new Vehicle(this->cur_seg));
    }
}

Toll::~Toll() {
    // cout << "Toll destruction." << endl;
    for (int i = 0; i < this->waiting_vehicles.size(); i++) {
        delete this->waiting_vehicles[i];
    }
}

void Toll::add_vehicles() {
    int temp = this->waiting_vehicles.size();
    // cout << ">> Waiting vehicles in toll: " << temp << endl;
    if (temp < this->waiting_v) {
        for (int i = 0 ; i < (this->waiting_v-temp) ; i++) {
            this->waiting_vehicles.push_back(new Vehicle(this->cur_seg));
        }   
    }
}

// temporary stores refence to the first vehicle, delete it from the vector 
// and then return the vehicle's reference 
Vehicle& Toll::remove_vehicle() {
    // after a lot of calls maybe the toll have no other vehicles
    if (waiting_vehicles.size() == 0) {
        this->add_vehicles();
    }
    Vehicle& temp = *this->waiting_vehicles.front();
    this->waiting_vehicles.erase(this->waiting_vehicles.begin());
    return temp;
}

void Toll::print() {
    for (int i = 0 ; i < this->waiting_vehicles.size(); i++) {
        this->waiting_vehicles[i]->print();
    }
}