// header file
#include <vector>
using namespace std;

/////////////////////////////////
static int round = 1;
extern int nsegs, k, percent;

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
    string id;      // node name-id -> f.e Node_0 / Node_1
    vector<Toll*> tolls;      // 3 tolls with employees
    vector<Toll*> e_tolls;    // 2 electronic tolls
public:
    Entrance(int);     // cur_seg
    ~Entrance();
    
    // segment::operate calls entrance::operate to insert 3*k vehicles 
    // from entrance's tolls to the segment's vector with vehicles
    void operate(vector<Vehicle*>&, int);
    void print();
};

class Segment {
private:
    int cur_seg;
    int percent;
    Entrance entrance;
    vector<Vehicle*> segment_vehicles;
    int capacity;
    Segment *prev_segment;
    Segment *next_segment;
    bool last_node;
public:
    Segment(int);
    ~Segment();

    void set_prev_next(Segment*, Segment*);
    void enter();   // enter vehicles from prev segment and this entry
    void exit();    // deleting vehicles from the vector segment_vehicles
    // vector<Vehicle*> pass();    // returning a vector with vehicles that changes segment
    void pass(vector<Vehicle*>&);   // adds vehicles from previous segment
    int get_no_of_vehicles() const;   
    void operate();     
    void print();
};

class Attiki_odos {
private:
    int all_vehicles;
    Segment** segments;
public:
    Attiki_odos();
    ~Attiki_odos();
    
    void operate();
};