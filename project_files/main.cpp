#include <iostream>
#include <vector>
#include "classes.h"
using namespace std;

int main (int argc, char* argv[]) {
    if (argc == 5) { 
        int n = atoi(argv[1]);       // number of simulation cycles
        int nsegs = atoi(argv[2]);       // number of road's sections
        int k = atoi(argv[3]);       // maximum amount of inserted cars
        int percent = atoi(argv[4]);        // cars percent
        
        srand(time(NULL));      // the start of the generator

        // construct the parts of the simulation
        Segment* seg_ar[nsegs];
        for (int i = 0 ; i < nsegs ; i++) {
            seg_ar[i] = new Segment(i);
        }

        // simulation starts here
        for (int i = 0 ; i < n ; i++) {
            // int rand_pos = rand() % n;       //
            for (int i = nsegs-1 ; i >= 0 ; i--) {
            
            
            
            }
        }
        cout << "\n--------------------" << endl;
    }
    else {
        cout << "Wrong given arguments" << endl;
    }
    return 0;
}