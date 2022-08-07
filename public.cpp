#include <iostream>
#include <string>

class PublicClass {
 public:
    void publicMethod() {
        std::cout << "PublicClass::publicMethod\n";
        privateMethod();
    }
 private:
    void privateMethod() {
        std::cout << className << "::privateMethod\n";
    }
    std::string className = "PublicClass";
};

int main() {

    PublicClass pub;
    pub.publicMethod();

}