#include <iostream>
#include "classes.h"
using namespace std;

int main (int argc, char* argv[]) {
    if (argc == 5) { 
        int n = atoi(argv[1]);       // number of simulation cycles
        int nsegs = atoi(argv[2]);       // number of road's sections
        int k = atoi(argv[3]);       // maximum amount of inserted cars
        int percent = atoi(argv[4]);        // cars percent
        
        srand(time(NULL));      // the start of the generator

        // simulation starts here
        Attiki_odos attiki_odos(nsegs, k, percent);
        for (int i = 0 ; i < n ; i++) {
            attiki_odos.operate();
        }
        cout << "\n--------------------" << endl;
    }
    else {
        cout << "Wrong given arguments" << endl;
    }
    return 0;
}