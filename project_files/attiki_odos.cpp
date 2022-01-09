#include <iostream>
#include <vector>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Attiki_odos::Attiki_odos(int nsegs,int k, int percent) {
    cout << "Highway in operation" << endl;
    this->nsegs = nsegs;
    this->all_cars = 0;
    // construct the segments of the highway
    Segment* seg_ar[nsegs];
    for (int i = 0 ; i < nsegs ; i++) {
        seg_ar[i] = new Segment(i, k, percent);
    }
}

Attiki_odos::~Attiki_odos() {
    cout << "Highway closed" << endl;
}

void Attiki_odos::operate() {
    cout << "Total cars: " << this->all_cars << endl;
    for (int i = this->nsegs-1 ; i >= 0 ; i--) {        
    
    }
}