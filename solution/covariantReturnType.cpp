#include <iostream>
#include <memory>
#include <string>

class Interface {
 public:
    virtual std::unique_ptr<Interface> clone() const = 0;
    virtual std::string getName() const = 0;
    virtual ~Interface() = default;
};

class Implementation1 : public Interface {
 public:
    std::unique_ptr<Interface> clone() const override {
        return std::unique_ptr<Interface>( new Implementation1(*this));
    }
    virtual std::string getName() const override {
        return "Implementation1::getName";
    }
};

class Implementation2 : public Interface {
 public:
    std::unique_ptr<Interface> clone() const override {
        return std::unique_ptr<Interface>( new Implementation2(*this));
    }
    virtual std::string getName() const override {
        return "Implementation2::getName";
    }
};

void cloneMe(std::unique_ptr<Interface> interface) {
    auto inter = interface->clone();
    std::cout << inter->getName() << '\n';
}

int main() {

    std::cout << '\n';

    std::unique_ptr<Interface> interface= std::make_unique<Implementation1>();
    cloneMe(std::move(interface));
    interface = std::make_unique<Implementation2>();
    cloneMe(std::move(interface));

    std::cout << '\n';

}