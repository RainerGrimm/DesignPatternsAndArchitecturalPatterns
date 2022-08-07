#include <iostream>
#include <set>

class Grafik {
public:
    virtual void print() const = 0;
    virtual ~Grafik() {} 
};

class GrafikKompositum : public Grafik {
    std::set<Grafik const*> children;
    typedef std::set<Grafik const*>::const_iterator grIter;
public:
    void print() const {
        for (grIter it = children.begin(); it != children.end(); it++) (*it)->print();
    }

    void add(Grafik const* component) {
        children.insert(component);
    }

    void remove(Grafik const* component) {
        children.erase(component);
    }
};

class Ellipse: public Grafik {
public:
    void print() const {
        std::cout << "Ellipse\n";
    }
};

int main(){
    Ellipse ellipse1, ellipse2, ellipse3, ellipse4;

    GrafikKompositum grafik1, grafik2, grafikGesamt;

    grafik1.add(&ellipse1);
    grafik1.add(&ellipse2);
    grafik1.add(&ellipse3);
    grafik2.add(&ellipse4);

    grafikGesamt.add(&grafik1);
    grafikGesamt.add(&grafik2);

    grafikGesamt.print();
}
