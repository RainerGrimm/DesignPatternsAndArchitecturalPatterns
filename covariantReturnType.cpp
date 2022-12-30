#include <iostream>
#include <string>

class Interface {
 public:
    virtual Interface* clone() const = 0;
    virtual std::string getName() const = 0;
    virtual ~Interface() = default;
};

class Implementation1 : public Interface {
 public:
    Implementation1* clone() const override {
        return new Implementation1(*this); 
    }
    virtual std::string getName() const override {
        return "Implementation1::getName";
    }
};

class Implementation2 : public Interface {
 public:
    Implementation2* clone() const override {
        return new Implementation2(*this); 
    }
    virtual std::string getName() const override {
        return "Implementation2::getName";
    }
};

void cloneMe(const Interface* interface) {
    auto* inter = interface->clone();
    std::cout << inter->getName() << '\n';
}

int main() {

    std::cout << '\n';

    Interface* interface = new Implementation1;
    cloneMe(interface);
    interface = new Implementation2;
    cloneMe(interface);

    std::cout << '\n';

}