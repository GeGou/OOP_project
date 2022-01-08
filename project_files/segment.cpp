#include <iostream>
#include <vector>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Segment::Segment(int i) {
    cout << "New segment. Give car capacity." << endl;
    cin >> this->capacity;
    this->index = i;
    vector<Car> cars;
    for (int i = 1; i <= 5; i++) {
        Car new_car;
        cars.push_back(new_car);
    }
}

Segment::~Segment() {
}