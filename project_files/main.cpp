#include <iostream>
#include "classes.h"
using namespace std;

int nsegs, k, percent;

int main (int argc, char* argv[]) {
    if (argc == 5) { 
        int n = atoi(argv[1]);       // number of simulation cycles
        nsegs = atoi(argv[2]);       // number of road's sections
        k = atoi(argv[3]);       // maximum amount of inserted vehicles
        percent = atoi(argv[4]);        // vehicles percent
        if ((n <= 0) || (nsegs <= 0) || (k <= 0) || (percent <= 0)) {
            cout << "Arguments take values greater than 0." << endl;
            return 0;
        }
        else if (percent > 100) {
            cout << "Percent's(last argument) range : 0 - 100" << endl;
            return 0;
        }
        srand(time(NULL));      // the start of the generator
        // simulation starts here
        Attiki_odos attiki_odos;
        for (int i = 0 ; i < n ; i++) {
            attiki_odos.operate();
        }
        cout << "--------------------" << endl;
    }
    else {
        cout << "Wrong set of arguments" << endl;
    }
    return 0;
}