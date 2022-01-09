#include <iostream>
#include <vector>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Attiki_odos::Attiki_odos() {
    cout << "Highway in operation" << endl;
    this->nsegs = 10;
    this->all_cars = 100;
}

Attiki_odos::~Attiki_odos() {
}

void Attiki_odos::operate() {
    cout << "Total cars: " << this->all_cars << endl ;
}