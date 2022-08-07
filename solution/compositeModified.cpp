#include <iostream>
#include <set>
#include <string>

class Grafik {
public:
    virtual void print() const = 0;
    virtual ~Grafik() {} 
};

class GrafikKompositum : public Grafik {
    std::set<Grafik const*> children;
public:
    void print() const {
        for (const auto& child: children) child->print();
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
        std::cout << "Ellipse ";
    }
};

class Circle: public Grafik {
public:
    void print() const {
        std::cout << "Circle ";
    }
};

void printGrafik(const std::string& name, const Grafik* graph){
    std::cout << name;
    graph->print();
    std::cout << "\n\n";
}

int main(){
    Ellipse ellipse1, ellipse2, ellipse3, ellipse4;
    Circle circle1, circle2;

    GrafikKompositum grafik1, grafik2, grafikGesamt;

    grafik1.add(&ellipse1);
    grafik1.add(&ellipse2);
    grafik1.add(&ellipse3);
    grafik2.add(&ellipse4);

    grafikGesamt.add(&grafik1);
    grafikGesamt.add(&grafik2);

    printGrafik("grafikGesamt.print(): ", &grafikGesamt);
   
    grafik1.add(&circle1);
    grafik2.add(&circle2);

    printGrafik("grafik2.print(): ", &grafik2);
    printGrafik("grafikGesamt.print(): ", &grafikGesamt);

    grafik1.remove(&ellipse1);
    grafik2.remove(&ellipse4);

    printGrafik("grafikGesamt.print(): ", &grafikGesamt);
}