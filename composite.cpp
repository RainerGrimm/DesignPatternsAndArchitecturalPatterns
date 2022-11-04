// composite.cpp

#include <iostream>
#include <string>
#include <vector>

class Graphic {
 public:
    virtual void print() const = 0;
    virtual ~Graphic() {} 
};

class GraphicComposite : public Graphic {
    std::vector<const Graphic*> children;
    const std::string& name;
 public:
    explicit GraphicComposite(const std::string& n): name(n){}
    void print() const override {
        std::cout << name << " ";
        for (auto c: children) c->print();
    }

    void add(const Graphic* component) {
        children.push_back(component);
    }

    void remove(const Graphic* component) {
        std::erase(children, component);
    }
};

class Ellipse: public Graphic {
 private:
    const std::string& name;
 public:
    explicit Ellipse(const std::string& n): name (n) {}
    void print() const override {
        std::cout << name << " ";
    }
};

int main(){

    std::cout << '\n';

    const std::string el1 = "ellipse1";
    const std::string el2 = "ellipse2";
    const std::string el3 = "ellipse3";
    const std::string el4 = "ellipse4";

    Ellipse ellipse1(el1);
    Ellipse ellipse2(el2);
    Ellipse ellipse3(el3);
    Ellipse ellipse4(el4);

    const std::string graph1 = "graphic1";
    const std::string graph2 = "graphic2";
    const std::string graph3 = "graphic3";

    GraphicComposite graphic1(graph1);
    GraphicComposite graphic2(graph2);
    GraphicComposite graphic(graph3);

    graphic1.add(&ellipse1);
    graphic1.add(&ellipse2);
    graphic1.add(&ellipse3);

    graphic2.add(&ellipse4);

    graphic.add(&graphic1);
    graphic.add(&graphic2);

    graphic1.print();
    std::cout << '\n';

    graphic2.print();
    std::cout << '\n';

    graphic.print();

    std::cout << '\n';

    graphic.remove(&graphic1);

    graphic.print();

    std::cout << "\n\n";

}
