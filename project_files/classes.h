// header file
#include <vector>
using namespace std;

/////////////////////////////////
static int round = 0;

class Vehicle {
private:
    int exit_node;      // random exit
    int segment;        // -1 while waiting to enter
    bool ready;      // false at start
public:
    Vehicle(int, int);      // seg, nsegs
    ~Vehicle();

    int get_exitnode();
    void set_segment(int);
    void set_ready();
    bool is_ready();
};

class Toll {
private:
    vector<Vehicle*> waiting_vehicles;      // 30 vehicles waiting in every toll
public:
    Toll(int, int);
    ~Toll();

    void add_vehicles(int, int);        // (int seg, int nsegs) / refill waiting vehicles vector
    Vehicle* remove_vehicle();
};

class Entrance {
private:
    int nsegs, cur_seg, k;
    string id;      // node name-id -> f.e Node_0 / Node_1
    vector<Toll*> tolls;      // 3 tolls with employees
    vector<Toll*> e_tolls;    // 5 electronic tolls
public:
    Entrance(int, int, int);
    ~Entrance();

    vector<Vehicle*> operate(int);      // int requested_vehicles -> vehicles from tolls to segment
};

class Segment {
private:
    int cur_seg;
    Entrance entrance;
    vector<Vehicle*> segment_vehicles;
    int capacity;
    Segment *next_segment;
    Segment *prev_segment;
public:
    Segment(int, int, int, int);
    ~Segment();
    
    void enter();   // enter vehicles from prev segment and this entry
    void exit();    // deleting vehicles from the vector segment_vehicles
    vector<Vehicle*> pass();    // returning a vector with vehicles that changes segment
    int get_no_of_vehicles();   
    void operate();     
};

class Attiki_odos {
private:
    int nsegs;
    int all_vehicles;
    Segment** segments;
public:
    Attiki_odos(int, int, int);
    ~Attiki_odos();
    void operate();
};