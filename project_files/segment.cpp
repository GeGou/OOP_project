#include <iostream>
#include <vector>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Segment::Segment(int cur_seg, int k, int percent) : entrance(cur_seg, k) {
    // cout << "Segment construction." << endl;
    cout << "--------------------------------------" << endl; 
    do {
        cout << "Segment_" << cur_seg << " - Give capacity in vehicles: ";
        cin >> this->capacity;      // user gives the capacity
        if (this->capacity <= 0) {
            cout << "Capacity should be more than 0." << endl;
        }
    } while (this->capacity <= 0);
    // cout << "--------------------------------------" << endl; 
    this->cur_seg = cur_seg;
    this->percent = percent;
    // just initializing the pointers and later takes correct values
    this->prev_segment = NULL;
    this->next_segment = NULL;
    int temp = rand() % this->capacity + 1;     // starting vehicles are 1-capacity
    for (int i = 0 ; i < temp ; i++) {
        this->segment_vehicles.push_back(new Vehicle(cur_seg));
        this->segment_vehicles[i]->set_segment(this->cur_seg);
    }
}

Segment::~Segment() {
    cout << "Segment destruction." << endl;

}

void Segment::set_prev_next(Segment* a, Segment* b) {
    this->prev_segment = a;
    this->next_segment = b;
}

void Segment::enter() {
    bool flag = false;
    // first enter vehicles from previous segment
    if (this->prev_segment != NULL) {
        this->prev_segment->pass(this->segment_vehicles);
    }    
    // after enter vehicles from the entry
    if (this->segment_vehicles.size() < this->capacity) {
        int temp = this->capacity - this->segment_vehicles.size();
        this->entrance.operate(this->segment_vehicles, temp);
        // if (entrance_vehicles.size() < temp) {
        //     cout << "~Delays at the node entrance: " << this->cur_seg << endl;
        //     flag = true;
        // }
    }
    if (flag == false) {
        cout << "~Keep safety distances at the segment after the node: " 
        << this->cur_seg << endl;
    }
}

void Segment::exit() {
    if (this->next_segment == NULL) {
        cout << "> Final node, only exit." << endl;
    }
    auto it = this->segment_vehicles.begin();
    int y = 0;
    while (it != this->segment_vehicles.end()) {
        // cout << y << "  " << this->segment_vehicles.size()  << endl;    
        if ((this->segment_vehicles[y]->get_exitnode() == this->cur_seg+1) 
        && (this->segment_vehicles[y]->is_ready() == true)) {
            cout << "<> Vehicle exits." << endl;
            // this->segment_vehicles[y]->print();
            it = this->segment_vehicles.erase(it);
        }
        else {
            it++;
        }
        y++;        // maybe need to increace y in the else {}
    }
}

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
    int y = 0;
    while (it != this->segment_vehicles.end()) {
        // the segment's ready vehicles to pass
        if ((this->segment_vehicles[y]->is_ready() == true) 
        && (this->segment_vehicles[y]->get_exitnode() > this->cur_seg+1)) {
            if (temp > 0) {     // space for vehicles in the next segment
                next_seg_vehicles.push_back(this->segment_vehicles[y]);
                it = this->segment_vehicles.erase(it);
                temp--;
            }
            else {      // no more space for vehicles in the next segment (Delays)
                cout << "~Delays after the node: " << this->next_segment->cur_seg << endl;
                break;
            }
        }
        else {
            it++;
        }
        y++;
    }
}

int Segment::get_no_of_vehicles() const {
    return this->segment_vehicles.size();
}

void Segment::operate() {
    this->exit();   // first -> vehicles exit
    this->enter();  // second -> enter vehicles
    // last -> select some vehicles to be ready (vehicles randomly inserted the vector)    
    int temp = get_no_of_vehicles() * this->percent/100;    // amount of cars to be ready
    for (int i = 0 ; i != temp ; i++) {
        this->segment_vehicles[i]->set_ready();
    }
    // this->print();
}

void Segment::print() {
    this->entrance.print();
    cout << "~ Segment_" << this->cur_seg << " -> Capacity: "
        << this->capacity << " / Vehicles:" << endl;
    vector<Vehicle*>::iterator a;
    int y = 0;
    for (a = this->segment_vehicles.begin(); a != this->segment_vehicles.end(); a++, y++) {
        this->segment_vehicles[y]->print();
    }
}