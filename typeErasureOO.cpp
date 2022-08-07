#include <iostream>
#include <string>
#include <vector>

struct BaseClass{
	virtual std::string getName() const = 0;
};

struct Bar: BaseClass{
	std::string getName() const override {
	    return "Bar";
	}
};

struct Foo: BaseClass{
	std::string getName() const override{
	    return "Foo";
	}
};

void printName(std::vector<BaseClass*> vec){
    for (auto v: vec) std::cout << v->getName() << '\n';
}


int main(){
	
	std::cout << '\n';
	
	Foo foo;
	Bar bar; 
	
	std::vector<BaseClass*> vec{&foo, &bar};
	
	printName(vec);
	
	std::cout << '\n';

}