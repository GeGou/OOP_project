#include <iostream>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Toll::Toll(int seg, int k) {
    cout << "Toll construction." << endl;
    for (int i = 0; i < k; i++) {
        int exit_node = rand() % k + seg;
        Car car(seg, exit_node);
        this->cars.push_back(car);
    }
}

Toll::~Toll() {
    cout << "Toll destruction." << endl;

}