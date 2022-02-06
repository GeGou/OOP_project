#include <iostream>
#include <vector>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Attiki_odos::Attiki_odos(int k, int percent) {
    cout << "Highway in operation" << endl 
        << "--------------------" << endl; 
    this->segments = new Segment*[nsegs];
    int sum;
    for (int cur_seg = 0 ; cur_seg < nsegs ; cur_seg++) {
        segments[cur_seg] = new Segment(cur_seg, k, percent);
        sum += this->segments[cur_seg]->get_no_of_vehicles();
    }
    this->all_vehicles = sum;
}

Attiki_odos::~Attiki_odos() {
    cout << "Highway closed" << endl;
    for (int i = 0 ; i < nsegs ; i++) {
        delete this->segments[i];
    }
    delete[] this->segments;
}

void Attiki_odos::operate() {
    cout << "----------------------" << endl 
        << "-> Total vehicles in highway: " << this->all_vehicles << endl;

    int sum = 0;
    for (int i = nsegs-1 ; i >= 0 ; i--) {        
        this->segments[i]->operate();       // changes the amount of segment's vehicles
        sum += this->segments[i]->get_no_of_vehicles();
        cout << "-> Segment: " << i << " / Vehicles: " 
            << this->segments[i]->get_no_of_vehicles() << endl;
    }
    this->all_vehicles = sum;
    cout << "-> Round: " << ++round << " / Vehicles: " << sum << endl;
}