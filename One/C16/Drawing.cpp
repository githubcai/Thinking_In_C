#include <vector>
#include "TPStash2.h"
#include "TStack2.h"
#include "Shape.h"
using namespace std;

class Drawing : public PStash<Shape>{
public:
    ~Drawing(){
        cout << "~Drawing" << endl;
    }
};

class Plan : public Stack<Shape>{
public:
    ~Plan(){
        cout << "~Plan" << endl;
    }
};

class Schematic : public vector<Shape*>{
public:
    ~Schematic(){
        cout << "~Schematic" << endl;
    }
};

template<class Iter>
void drawAll(Iter start, Iter end){
    while(start!=end){
        (*start)->draw();
        start++;
    }
}

int main(){
    Drawing d;
    d.add(new Circle);
    d.add(new Square);
    d.add(new Line);
    Plan p;
    p.push(new Circle);
    p.push(new Square);
    p.push(new Line);
    Schematic s;
    s.push_back(new Square);
    s.push_back(new Circle);
    s.push_back(new Line);
    Shape* sarray[] = {new Circle, new Square, new Line};
    cout << "Drawing d:" << endl;
    drawAll(d.begin(), d.end());
    cout << "Plan p:" << endl;
    drawAll(p.begin(), p.end());
    cout << "Schematic s:" << endl;
    drawAll(s.begin(), s.end());
    cout << "Array sarray:" << endl;
    drawAll(sarray, sarray+sizeof(sarray)/sizeof(*sarray));
    cout << "End of main" << endl;
}
