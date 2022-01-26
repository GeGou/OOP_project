#include <iostream>
#include <vector>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Attiki_odos::Attiki_odos(int nsegs, int k, int percent) {
    cout << "Highway in operation" << endl << "--------------------" << endl; 
    this->nsegs = nsegs;
    this->all_vehicles = 0;
    this->segments = new Segment*[nsegs];
    for (int cur_seg = 0 ; cur_seg < nsegs ; cur_seg++) {
        segments[cur_seg] = new Segment(nsegs, cur_seg, k, percent);
    }
}

Attiki_odos::~Attiki_odos() {
    cout << "Highway closed" << endl;
    for (int i = 0 ; i < this->nsegs ; i++) {
        delete this->segments[i];
    }
    delete[] this->segments;
}

void Attiki_odos::operate() {
    cout << "-> Total vehicles: " << this->all_vehicles << endl;

    int sum = 0;
    for (int i = this->nsegs-1 ; i >= 0 ; i--) {        
        this->segments[i]->operate();       // changes the amount of segment's vehicles
        sum += this->segments[i]->get_no_of_vehicles();
    }
    cout << "-> Round: " << ++round << " / Vehicles: " << sum << endl;
}