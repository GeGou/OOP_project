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

class Segment : public Attiki_odos {
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
    Entry(/* args */);
    ~Entry();
};

class Toll : public Entry {
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
    Entry *output_node;
    // Segment *segment;       // -1 while waiting to enter
    int segment;
    bool is_ready;      // false at start
public:
    Car(/* args */);
    ~Car();
};