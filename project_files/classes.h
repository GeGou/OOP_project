// header file
#include <vector>
using namespace std;

/////////////////////////////////
static int round = 0;
extern int nsegs;

class Vehicle {
private:
    int exit_node;      // random exit
    int segment;        // -1 while waiting to enter
    bool ready;      // false at start
public:
    Vehicle(int);      // seg, nsegs
    ~Vehicle();

    int get_exitnode() const;
    void set_segment(int);
    void set_ready();
    bool is_ready() const;
    void print() const;
};

class Toll {
private:
    int cur_seg;
    int waiting_v;      // random with range 5-15
    vector<Vehicle*> waiting_vehicles;      // 10 vehicles waiting in each toll
public:
    Toll(int);
    ~Toll();

    void add_vehicles();        // refill waiting vehicles vector
    Vehicle& remove_vehicle();      // remove and return a vehicle from toll to segment
    void print();
};

class Entrance {
private:
    int cur_seg;
    int k;
    string id;      // node name-id -> f.e Node_0 / Node_1
    vector<Toll*> tolls;      // 3 tolls with employees
    vector<Toll*> e_tolls;    // 2 electronic tolls
public:
    Entrance(int, int);     // cur_seg, k
    ~Entrance();
    
    // segment::operate calls entrance::operate and requests x vehicles
    // witch returned in a vector from vehicles. This function maybe
    // returns less than requested vehicles because of the 3*k (maximum vehicles)
    vector<Vehicle*> operate(int);      // int requested_vehicles -> return vector with vehicles from tolls
    void print();
};

class Segment {
private:
    int cur_seg;
    int percent;
    Entrance entrance;
    vector<Vehicle*> segment_vehicles;
    int capacity;
    Segment *next_segment;
    Segment *prev_segment;
public:
    Segment(int, int, int);
    ~Segment();
    
    void enter();   // enter vehicles from prev segment and this entry
    void exit();    // deleting vehicles from the vector segment_vehicles
    vector<Vehicle*> pass();    // returning a vector with vehicles that changes segment
    int get_no_of_vehicles();   
    void operate();     
    void print();
};

class Attiki_odos {
private:
    int all_vehicles;
    Segment** segments;
public:
    Attiki_odos(int, int);
    ~Attiki_odos();
    void operate();
};