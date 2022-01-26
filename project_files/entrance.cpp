#include <iostream>
#include <vector>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Entrance::Entrance(int nsegs, int cur_seg, int k) {
    // cout << "Entrance construction." << endl;
    this->nsegs = nsegs;
    this->cur_seg = cur_seg;
    this->k = k;
    string temp = "Node_";
    this->id = temp.append(to_string(cur_seg));      // making the node unique
    // employee tolls
    for (int i = 0; i < 3; i++) {
        this->tolls.push_back(new Toll(nsegs, cur_seg));
    }
    // e-tolls
    for (int i = 0; i < 5; i++) {
        this->e_tolls.push_back(new Toll(nsegs, cur_seg));
    }
}

Entrance::~Entrance() {
    cout << "Entrance destruction." << endl;
    // this->tolls.clear();
    // this->e_tolls.clear();
}

vector<Vehicle*> Entrance::operate(int req_vehicles) {
    // first step -> remove vehicles from entrance /return them to segment
    vector<Vehicle*> removed_vehicles;      // returned vector

    while (removed_vehicles.size() < req_vehicles) {
        // tolls with employee
        vector<Toll*>::iterator a;
        int y = 0;
        int count = 0;
        for (a = tolls.begin(); a != tolls.end(); a++, y++) {
            if ((removed_vehicles.size() < req_vehicles) && (count < this->k)) {
                removed_vehicles.push_back(this->tolls[y]->remove_vehicle());
                count++;
            }
        }
        // e-tolls
        vector<Toll*>::iterator b;
        y = 0;
        count = 0;
        for (b = e_tolls.begin(); b != e_tolls.end(); b++, y++) {
            if ((removed_vehicles.size() < req_vehicles) && (count < 2*this->k)) {
                removed_vehicles.push_back(this->e_tolls[y]->remove_vehicle());
            }
        }
    }
    // updating k for the next round
    if (req_vehicles < this->k*3) {
        this->k--;
    }
    else if (req_vehicles == this->k*3) {
        this->k++;
    }

    // second step -> refill the waiting vehicles in tolls
    vector<Toll*>::iterator a;
    int y = 0;
    for (a = tolls.begin(); a != tolls.end(); a++, y++) {
        tolls[y]->add_vehicles(this->cur_seg, this->nsegs);
    }
    vector<Toll*>::iterator b;
    y = 0;
    for (b = e_tolls.begin(); b != e_tolls.end(); b++, y++) {
        e_tolls[y]->add_vehicles(this->cur_seg, this->nsegs);
    }
    return removed_vehicles;
}