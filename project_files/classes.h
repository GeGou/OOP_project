// header file
#include <vector>
using namespace std;

/////////////////////////////////
static int round = 0;

class Car {
private:
    int exit_node;      // random exit
    int segment;        // -1 while waiting to enter
    bool ready;      // false at start
public:
    Car(int, int);      // seg, nsegs
    ~Car();

    int get_exitnode();
    void set_segment(int);
    void set_ready();
    bool is_ready();
};

class Toll {
private:
    vector<Car*> waiting_cars;      // 30 cars waiting in every toll
public:
    Toll(int, int);
    ~Toll();

    void add_cars(int, int);        // (int seg, int nsegs) / refill waiting cars vector
    Car* remove_car();
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

    vector<Car*> operate(int);      // int requested_cars -> cars from tolls to segment
};

class Segment {
private:
    int cur_seg;
    Entrance entrance;
    vector<Car*> segment_cars;
    int capacity;
    Segment *next_segment;
    Segment *prev_segment;
public:
    Segment(int, int, int, int);
    ~Segment();
    
    bool enter(Car&);   // return true/false if a car moved to new seg or not
    void exit();    // deleting cars from the vector segment_cars
    vector<Car*> pass();    // returning a vector with cars that changes segment
    int get_no_of_vehicles();   
    void operate(); 
};

class Attiki_odos {
private:
    int nsegs;
    int all_cars;
    Segment** segments;
public:
    Attiki_odos(int, int, int);
    ~Attiki_odos();
    void operate();
};