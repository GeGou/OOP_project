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
    // first enter vehicles from prev segment
    if (this->prev_segment != NULL) {
        // vector<Vehicle*> pass_vehicles = this->prev_segment->pass();
        this->prev_segment->pass(this->segment_vehicles);
        // add new vector to the old one
        // for (int i = 0 ; i < pass_vehicles.size() ; i++) {
        //     if (this->capacity == this->segment_vehicles.size()) {
        //         break;
        //     }
        //     else {
        //         this->segment_vehicles.push_back(pass_vehicles[i]);
        //     }
        // }
    }    

    // after enter vehicles from the entry
    if (this->segment_vehicles.size() < this->capacity) {
        int temp = this->capacity - this->segment_vehicles.size();
        vector<Vehicle*> entrance_vehicles = this->entrance.operate(temp);
        if (entrance_vehicles.size() < temp) {
            cout << "~Delays at the node entrance: " << this->cur_seg << endl;
            flag = true;
        }
        // add new vector to the old one
        for (int i = 0 ; i < entrance_vehicles.size() ; i++) {
            if (this->capacity == this->segment_vehicles.size()) {
                break;
            }
            else {
                this->segment_vehicles.push_back(entrance_vehicles[i]);
            }
        }
    }
    if (flag == false) {
        cout << "~Keep safety distances at the segment after the node: " << this->cur_seg << endl;
    }
}

void Segment::exit() {
    if (this->next_segment == NULL) {
        cout << "> Final node, only exit." << endl;
    }
    vector<Vehicle*>::iterator i;
    int y = 0;
    // for (int i = 0; i != segment_vehicles.size(); i++, y++) {
    for (i = this->segment_vehicles.begin(); i != this->segment_vehicles.end(); i++) {
        // cout << y << "  " << this->segment_vehicles.size() << endl;
        if ((this->segment_vehicles[y]->get_exitnode() == this->cur_seg + 1) 
        && (this->segment_vehicles[y]->is_ready() == true)) {
            cout << "<> Vehicle exits --> " << endl;
            cout << "HERE: " << y << "  " << this->segment_vehicles.size()  << endl;
            this->segment_vehicles[y]->print();
            this->segment_vehicles.erase(i);
        }
        cout << y << "  " << this->segment_vehicles.size()  << endl;
        if (y < this->segment_vehicles.size() - 1) {
            cout << "HERE2" << endl;
            y++;
        }
    }
}

// vector<Vehicle*> Segment::pass() {
//     // passing vehicles in the next segment
//     vector<Vehicle*> passing_vehicles;
//     vector<Vehicle*>::iterator i;
//     int y = 0;
//     // temp = empty space for vehicles in the next segment
//     int temp = this->next_segment->capacity - this->next_segment->segment_vehicles.size();
//     for (i = segment_vehicles.begin(); i != segment_vehicles.end(); i++, y++) {
//         if (y == temp) {
//             cout << "~Delays after the node: " << this->prev_segment->cur_seg << endl;
//             break;
//         }
//         if (segment_vehicles[y]->is_ready() == true) {
//             passing_vehicles.push_back(segment_vehicles[y]);
//             segment_vehicles.erase(i);
//         }
//     }
//     return passing_vehicles;
// }

void Segment::pass(vector<Vehicle*> &next_seg_vehicles) {
    vector<Vehicle*>::iterator i;
    int y = 0;
    // temp = empty space for vehicles in the next segment
    int temp = this->next_segment->capacity - next_seg_vehicles.size();
    cout << "Pass temp: " << temp << endl;
    for (i = this->segment_vehicles.begin(); i != this->segment_vehicles.end(); i++, y++) {
        if ((this->segment_vehicles[y]->is_ready() == true) && 
            (this->segment_vehicles[y]->get_exitnode() > this->cur_seg+1)) {
            if (temp > 0) {
                next_seg_vehicles.push_back(this->segment_vehicles[y]);
                // this->segment_vehicles.erase(i);
                temp--;
            }
            else {
                cout << "~Delays after the node: " << this->next_segment->cur_seg << endl;
                break;
            }
        }
    }
}

int Segment::get_no_of_vehicles() const {
    return this->segment_vehicles.size();
}

void Segment::operate() {
    // vehicles exit
    // if (this->prev_segment != NULL) {   // first node haven't exit
    //     this->exit();
    // }
    // if (this->prev == 0) {   // first node haven't exit
        this->exit();
    // }
    // pass() of x-1 segment is called by the enter of segment x
    // enter vehicles
    this->enter();
    // select random vehicles to be ready    
    int temp = get_no_of_vehicles() * this->percent/100;    // amount of cars to be ready
    int y = 0;
    vector<Vehicle*>::iterator i;
    for (i = segment_vehicles.begin(); i != segment_vehicles.end(); i++, y++) {
        segment_vehicles[y]->set_ready();
        if (y == temp) {
            break;
        }
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