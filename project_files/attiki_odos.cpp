#include <iostream>
#include <vector>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Attiki_odos::Attiki_odos() {
    cout << "Highway in operation" << endl;
    this->segments = new Segment*[nsegs];
    int sum = 0;
    for (int cur_seg = 0 ; cur_seg < nsegs ; cur_seg++) {
        this->segments[cur_seg] = new Segment(cur_seg);
        sum += this->segments[cur_seg]->get_no_of_vehicles();
    }
    this->all_vehicles = sum;
    cout << "-------------------------------\n" << "Starting amount of vehicles: " 
        << this->all_vehicles << endl;
    // setting the pointer to previous and next segment
    this->segments[0]->set_prev_next(NULL, this->segments[1]);
    this->segments[nsegs-1]->set_prev_next(this->segments[nsegs-2], NULL);
    for (int i = 1 ; i < nsegs-1 ; i++) {
        this->segments[i]->set_prev_next(this->segments[i-1], this->segments[i+1]);
    }
}

Attiki_odos::~Attiki_odos() {
    cout << "Highway closed" << endl;
    for (int i = 0 ; i < nsegs ; i++) {
        delete this->segments[i];
    }
    delete[] this->segments;
}

void Attiki_odos::operate() {
    cout << "--------------------------------\n" << ">>>>> Simulation cycle : " 
        << round++ << " <<<<<" << endl;
    int sum = 0;
    for (int i = nsegs-1 ; i >= 0 ; i--) {        
        this->segments[i]->operate();       // changes the amount of segment's vehicles
        sum += this->segments[i]->get_no_of_vehicles();
        cout << "-> Segment: " << i << " / Vehicles: " 
            << this->segments[i]->get_no_of_vehicles() << endl;
    }
    this->all_vehicles = sum;
    // cout << "-> Round: " << round++ << " / Vehicles: " << sum0 << endl;
    cout << "-> Total vehicles in highway: " << this->all_vehicles << endl;
}