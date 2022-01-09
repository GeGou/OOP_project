// header file
#include <vector>
using namespace std;

/////////////////////////////////
class Segment;
class Entry;
class Toll;
class Car;

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

class Segment {
private:
    int index;
    Entry entry;
    int segment_cars;
    int capacity;
    Segment *next_segment;
    Segment *prev_segment;
public:
    Segment(int, int, int);
    ~Segment();
    
    void enter();
    void exit();
    void pass();
    int get_no_of_vehicles();
    void operate(); 
};

class Entry {
private:
    string id;      // entry name-id
    vector<Toll> tolls;      // tolls with employees
    vector<Toll> e_tolls;    // electronic tolls
public:
    Entry(int, int);
    ~Entry();

    void operate();
};

class Toll {
private:
    // int waiting_cars;
    vector<Car> cars;
public:
    Toll(int, int);
    ~Toll();

    void remove_cars();
    void add_cars();
};

class Car {
private:
    int exit_node;
    int segment;        // -1 while waiting to enter
    bool is_ready;      // false at start
public:
    Car(int, int);      // seg, nsegs
    ~Car();

    void seg(int);
    void ready();
};