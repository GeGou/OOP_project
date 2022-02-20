#include <iostream>
#include <vector>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Segment::Segment(int cur_seg) : entrance(cur_seg) {
    // cout << "Segment construction." << endl;
    cout << "--------------------------------------" << endl; 
    do {
        cout << "Segment_" << cur_seg << " - Give capacity in vehicles: ";
        cin >> this->capacity;      // user gives the capacity
        if (this->capacity <= 0) {
            cout << "Capacity should be more than 0." << endl;
        }
    } while (this->capacity <= 0);
    this->cur_seg = cur_seg;
    // initializing the pointers to be NULL at first
    this->prev_segment = NULL;
    this->next_segment = NULL;
    int temp = rand() % this->capacity/2 + 1;     // starting vehicles are about 1 to capacity/2
    for (int i = 0 ; i < temp ; i++) {
        this->segment_vehicles.push_back(new Vehicle(cur_seg));
        this->segment_vehicles[i]->set_segment(this->cur_seg);
    }
}

Segment::~Segment() {
    // cout << "Segment destruction." << endl;
    for (int i = 0 ; i < this->segment_vehicles.size() ; i++) {
        delete this->segment_vehicles[i];
    }
    this->segment_vehicles.clear();
}

// setting pointer to previous and next segment of each segment
void Segment::set_prev_next(Segment* a, Segment* b) {
    this->prev_segment = a;
    this->next_segment = b;
}

// after some vehicles have left the segment ,iτ's time to enter new vehicles
// first from previous segment and then ,if segment is't full, from entrance
void Segment::enter() {
    bool flag = false;
    // first enter vehicles from previous segment
    if (this->prev_segment != NULL) {
        this->prev_segment->pass(this->segment_vehicles);
    }    
    // after enter vehicles from the entrance
    int temp = this->capacity - this->segment_vehicles.size();
    if (temp > 0) {
        this->entrance.operate(this->segment_vehicles, temp);
        if (3*k > temp) {
            cout << "~Delays at the node entrance: " << this->cur_seg << endl;
            flag = true;
        }
    }
    if (flag == false) {
        cout << "~Keep safety distances at the segment after the node: " 
        << this->cur_seg << endl;
    }
}

// finding and remove vehicles with destinition node this node
void Segment::exit() {
    if (this->next_segment == NULL) {
        cout << "> Final node, only exit." << endl;
    }
    auto it = this->segment_vehicles.begin();
    while (it != this->segment_vehicles.end()) {   
        if (((*it)->get_exitnode() == this->cur_seg+1) && ((*it)->is_ready() == true)) {
            cout << "<> Vehicle exits." << endl;
            // this->segment_vehicles[y]->print();
            delete *it;
            it = this->segment_vehicles.erase(it);
        }
        else { it++; }
    }
}

// called each time from the next segment to pass the ready vehicles
// fron n-1 segment to n segment by adding vehicles to n vehicle's vector 
void Segment::pass(vector<Vehicle*> &next_seg_vehicles) {
    // temp = space for vehicles in the next segment
    int temp = this->next_segment->capacity - next_seg_vehicles.size();
    if (temp > 0) {
        cout << "Space for passing vehicles: " << temp << endl; 
    }
    else {
        cout << "No space to pass vehicles." << endl;
    }
    auto it = this->segment_vehicles.begin();
    while (it != this->segment_vehicles.end()) {
        // the segment's ready vehicles to pass
        if (((*it)->is_ready() == true) && ((*it)->get_exitnode() > this->cur_seg+1)) {
            if (temp > 0) {     // space for vehicles in the next segment
                ((*it))->set_ready(false);
                next_seg_vehicles.push_back(*it);
                it = this->segment_vehicles.erase(it);
                temp--;
            }
            else {      // no more space for vehicles in the next segment (Delays)
                cout << "~Delays after the node: " << this->next_segment->cur_seg << endl;
                break;
            }
        }
        else { it++; }
    }
}

int Segment::get_no_of_vehicles() const {
    return this->segment_vehicles.size();
}

void Segment::operate() {
    this->exit();   // first -> vehicles exit
    this->enter();  // second -> enter vehicles
    // last -> select some vehicles to be ready (vehicles randomly inserted the vector)    
    int temp = get_no_of_vehicles() * percent/100;    // amount of cars to be ready
    for (int i = 0 ; i < temp ; i++) {
        this->segment_vehicles[i]->set_ready(true);
    }
    // this->print();
}

// print all segment's vehicles info by uncomment the command in operate
void Segment::print() {
    // this->entrance.print();      // if we need to list the waiting vehicles in tolls
    cout << "Segment: " << this->cur_seg << " -> Capacity: "
        << this->capacity << " / Vehicles:" << endl;
    for (int i = 0 ; i < this->segment_vehicles.size() ; i++) {
        this->segment_vehicles[i]->print();
    }
}