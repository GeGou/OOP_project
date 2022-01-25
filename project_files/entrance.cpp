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

vector<Car*> Entrance::operate(int req_cars) {
    // first step -> remove cars from entrance /return them to segment
    vector<Car*> removed_cars;

    // 8ELEI DOULEIA AYTH H FASH ME TO POSA OXHMATA 8A MPAINOYN STO SEGMENT
    while ( removed_cars.size() < req_cars) {
        vector<Toll*>::iterator i;
        int y = 0;
        for (i = tolls.begin(); i != tolls.end(); i++, y++) {
            if (removed_cars.size() < req_cars) {
                removed_cars.push_back(this->tolls[y]->remove_car());
            }
        }
    }
    // updating k for the next round
    if (this->k*3 < req_cars) {
        this->k--;
    }
    else {
        this->k++;
    }

    // second step -> refill the waiting cars in tolls
    vector<Toll*>::iterator a;
    int y = 0;
    for (a = tolls.begin(); a != tolls.end(); a++, y++) {
        tolls[y]->add_cars(this->cur_seg, this->nsegs);
    }
    vector<Toll*>::iterator b;
    int y = 0;
    for (b = e_tolls.begin(); b != e_tolls.end(); b++, y++) {
        e_tolls[y]->add_cars(this->cur_seg, this->nsegs);
    }
    return removed_cars;
}