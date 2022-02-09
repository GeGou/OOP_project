#include <iostream>
#include <vector>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Entrance::Entrance(int cur_seg) : cur_seg(cur_seg) {
    // cout << "Entrance construction." << endl;
    string temp = "Node_";
    this->id = temp.append(to_string(cur_seg));      // making the node unique
    // employee tolls
    for (int i = 0; i < 3; i++) {
        this->tolls.push_back(new Toll(cur_seg));
    }
    // e-tolls
    for (int i = 0; i < 2; i++) {
        this->e_tolls.push_back(new Toll(cur_seg));
    }
}

Entrance::~Entrance() {
    // cout << "Entrance destruction." << endl;
    for (int i = 0; i < this->tolls.size(); i++) {
        delete this->tolls[i];
    }
    for (int i = 0; i < this->e_tolls.size(); i++) {
        delete this->e_tolls[i];
    }
}

void Entrance::operate(vector<Vehicle*>& seg_vehicles, int space) {
    // first step
    int temp = space;
    if (k*3 < space) {
        temp = k*3;
    } 
    // need to pass "temp" amount of vehicles from all the tolls
    int temp0 = 0, i = 0;
    while ((temp > 0) && (temp0 < k)) {
        // tolls with employee - passes one vehicle from each toll to the vector
        if (i == this->tolls.size()) {
            i = 0;
        }
        seg_vehicles.push_back(&this->tolls[i]->remove_vehicle());
        i++; temp--; temp0++;
    }
    temp0 = 0, i = 0;
    while ((temp > 0) && (temp0 < 2*k)) {
        // e-tolls - passes one vehicle from each e-toll to the vector
        if (i == this->e_tolls.size()) {
            i = 0;
        }
        seg_vehicles.push_back(&this->e_tolls[i]->remove_vehicle());
        i++; temp--; temp0++;
    }
    // updating k for the next round
    if (space < k*3) { k--; }
    else { k++; }
    // second step -> refill the waiting vehicles in tolls
    for (int i = 0; i != tolls.size(); i++) {
        this->tolls[i]->add_vehicles();
    }
    for (int i = 0 ; i != e_tolls.size(); i++) {
        this->e_tolls[i]->add_vehicles();
    }
}

void Entrance::print() {
    cout << this->id << " :" << endl;
    for (int i = 0 ; i < this->tolls.size() ; i++) {
        this->tolls[i]->print();
    }
    for (int i = 0 ; i < this->e_tolls.size() ; i++) {
        this->e_tolls[i]->print();
    }
}