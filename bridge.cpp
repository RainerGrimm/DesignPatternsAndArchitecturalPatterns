#include <iostream>

class Implementor {
public:
    virtual void implementation() = 0;

    virtual ~Implementor() = default;
};
 
class ImplementorA: public Implementor {
public:
    ImplementorA() = default;
 
    void implementation() {
        std::cout << "ImplementatorA::implementation" << '\n';
    }
};
 
class ImplementorB: public Implementor {
public:
    ImplementorB() = default;

    void implementation() {
        std::cout << "ImplementatorB::implementation" << '\n';
    }
};

class Abstraction {
public:
    virtual void function()= 0;
    virtual ~Abstraction() = default;
};

class RefinedAbstraction: public Abstraction {
public:
    RefinedAbstraction(Implementor& impl) : 
		implementor(impl) {
    }
 
    void function() {
        std::cout << "RefinedAbstradtion::function\n";
        implementor.implementation();
    }

    void refinedFunction() {
        std::cout << "RefinedAbstradtion::function\n";
        implementor.implementation();
    }
private:
    Implementor& implementor;
};
 
int main() {

    ImplementorA implementorA;
    ImplementorB implementorB;
 
    RefinedAbstraction refinedAbstraction1(implementorA);
    RefinedAbstraction refinedAbstraction2(implementorB);

    Abstraction *abstraction1 = &refinedAbstraction1;
    Abstraction *abstraction2 = &refinedAbstraction2;

    abstraction1->function();
    refinedAbstraction1.refinedFunction();

    std::cout << '\n';

    abstraction2->function();
    refinedAbstraction2.refinedFunction();

}