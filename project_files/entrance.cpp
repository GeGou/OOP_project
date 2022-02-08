#include <iostream>
#include <vector>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Entrance::Entrance(int cur_seg, int k) {
    // cout << "Entrance construction." << endl;
    this->cur_seg = cur_seg;
    this->k = k;
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
    cout << "Entrance destruction." << endl;
    // this->tolls.clear();
    // this->e_tolls.clear();
}

void Entrance::operate(vector<Vehicle*>& seg_vehicles, int space) {
    // first step
    int temp = space;   // maximum vehicles to enter from tolls to segment
    if (this->k*3 < space) {
        temp = this->k*3;
    }  
    int temp0 = 0;
    while ((temp > 0) && (temp0 < this->k)) {
        // tolls with employee - passes one vehicle from each toll to the vector
        int i = 0;
        while (((i != this->tolls.size()) && (temp0 < this->k))) {
            // prepei na elenxw kai to temp pou ginetai --
            seg_vehicles.push_back(&this->tolls[i]->remove_vehicle());
            i++; temp--; temp0++;
        }
    }
    temp0 = 0;
    while ((temp > 0) && (temp0 < 2*this->k)) {
        // e-tolls - passes one vehicle from each e-toll to the vector
        int i = 0;
        while ((i != this->e_tolls.size()) && (temp < 2*this->k)) {
            seg_vehicles.push_back(&this->e_tolls[i]->remove_vehicle());
            i++; temp--; temp0++;
        }
    }
    // updating k for the next round
    if (space < this->k*3) {
        this->k--;
    }
    else {  // if (space == this->k*3) {
        this->k++;
    }
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
    vector<Toll*>::iterator a, b;
    int y = 0;
    for (a = tolls.begin(); a != tolls.end(); a++, y++) {
        this->tolls[y]->print();
    }
    y = 0;
    for (b = e_tolls.begin(); b != e_tolls.end(); b++, y++) {
        this->e_tolls[y]->print();
    }
}