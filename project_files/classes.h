// header file
#include <vector>
using namespace std;

/////////////////////////////////
class Car {
private:
    // int exit_node;
    int segment;        // -1 while waiting to enter
    bool ready;      // false at start
public:
    Car(int, int);      // seg, nsegs
    ~Car();
    int exit_node;

    void seg(int);
    // void ready();
    bool is_ready();
    void operate();
};

class Toll {
private:
    // int waiting_cars;
    int k;
    vector<Car*> cars;
public:
    Toll(int, int, int);
    ~Toll();

    void add_cars(int);
    void remove_cars(int);
};

class Entrance {
private:
    string id;      // entrance name-id
    vector<Toll*> tolls;      // tolls with employees
    vector<Toll*> e_tolls;    // electronic tolls
public:
    Entrance(int, int, int);
    ~Entrance();

    void operate();
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
    
    bool enter(Car&);   // isws 8elei *car 
    void exit();
    vector<Car*> pass();
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