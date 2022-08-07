#include <iostream>
#include <memory>

using namespace std;

class Strat {
public:
    virtual void operator()() = 0;
    virtual ~Strat() {}
};

class Kontext {
    shared_ptr<Strat> _strat;
public:
    Kontext() : _strat(nullptr) {}
    void setStrategy(shared_ptr<Strat> strat)  { _strat = strat; }
    void strategy()  { if (_strat) (*_strat)(); }
};

class Strategy1 : public Strat {
public:
    void operator()() { cout << "Foo\n"; }
};

class Strategy2 : public Strat {
public:
    void operator()() { cout << "Bar\n"; }
};

class Strategy3 : public Strat {
public:
    void operator()() { cout << "FooBar\n"; }
};

int main() {
    Kontext k;

    k.setStrategy( std::shared_ptr<Strat>(new Strategy1) );
    k.strategy();

    k.setStrategy( std::shared_ptr<Strat>(new Strategy2) );
    k.strategy();

    k.setStrategy( std::shared_ptr<Strat>(new Strategy3) );
    k.strategy();
}
