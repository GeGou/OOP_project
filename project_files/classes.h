// header file
using namespace std;

/////////////////////////////////
class Entry;

class Attiki_odos {
private:
    int nsegs;
    int all_cars;
public:
    Attiki_odos(/* args */);
    ~Attiki_odos();
    void operate();
};

class Segment {
private:
    int index;
    Entry *entry;
    int segment_cars;
    int capacity;
    Segment *next_segment;
    Segment *prev_segment;
public:
    Segment(int);
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
    int tolls;      // tolls with employees
    int e_tolls;    // electronic tolls
public:
    Entry(int);
    ~Entry();

    void operate();
};

class Toll {
private:
    int waiting_cars;
public:
    Toll(/* args */);
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
    Car(int, int);
    ~Car();

    void seg(int);
    void ready();
};