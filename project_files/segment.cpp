#include <iostream>
#include <vector>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Segment::Segment(int nsegs, int cur_seg, int k, int percent) : entrance(nsegs, cur_seg, k) {
    // cout << "Segment construction." << endl;
    cout << "Segment_" << cur_seg << " - Give capacity in cars: ";
    cin >> this->capacity;      // user gives the capacity
    cout << "------------------------------------" << endl; 
    this->cur_seg = cur_seg;
    if (cur_seg == 0) {
        this->prev_segment = NULL;
    }
    else if (cur_seg == nsegs - 1) {
        this->next_segment = NULL;
    }
    int temp = rand() % 30 + 10;     // starting cars are 10-40
    for (int i = 0 ; i < temp ; i++) {
        this->segment_cars.push_back(new Car(cur_seg, nsegs));
    }
}

Segment::~Segment() {
    cout << "Segment destruction." << endl;

}

bool Segment::enter(Car& car) {
    if (this->prev_segment == NULL) {
        // ENTOLES
    }
    // this->entrance.operate();   // epiostrefei synolo oxhmatwn
    if (get_no_of_vehicles() < this->capacity) {
        this->segment_cars.push_back(&car);
        return true;
    }
    return false;
}

void Segment::exit() {

    vector<Car*>::iterator i;
    int y = 0;
    for (i = segment_cars.begin(); i != segment_cars.end(); i++, y++) {
        this->segment_cars;
        if (this->next_segment == NULL) {
            cout << "Erase all cars, road is finished" << endl;
            segment_cars.erase(i);
        }
        else if (segment_cars[y]->exit_node == this->cur_seg) {
            segment_cars.erase(i);
            cout << "Erase car" << endl;
        }
     }
    // this->entrance.operate();
}

vector<Car*> Segment::pass() {
    // passing cars in the next segment
    vector<Car*> passing_cars;
    vector<Car*>::iterator i;
    int y = 0;
    for (i = segment_cars.begin(); i != segment_cars.end(); i++, y++) {
        if (segment_cars[y]->exit_node > this->cur_seg) {
            passing_cars.push_back(segment_cars[y]);
            segment_cars.erase(i);
        }
    }
    return passing_cars;
}

int Segment::get_no_of_vehicles() {
    return this->segment_cars.size();
}

void Segment::operate() {
    int cars = get_no_of_vehicles() / 2;    // f.e. 50/2 -> 25
    int temp = rand() % cars;       // f.e. if cars=25 -> 0-24  will be ready
    
    this->exit();
}