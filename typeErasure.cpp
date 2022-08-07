#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Object {
	
 public:
    template <typename T> 
    explicit Object(const T& obj): object(std::make_shared<Model<T>>(std::move(obj))){}
      
    std::string getName() const { 
        return object->getName(); 
    }
	
    struct Concept {
       virtual ~Concept() {}
	   virtual std::string getName() const = 0;
    };

    template< typename T > 
    struct Model : Concept {
       explicit Model(const T& t) : object(t) {}
	   std::string getName() const override {
		   return object.getName();
	   }
     private:
       T object;
    };

    std::shared_ptr<const Concept> object;
};


void printName(std::vector<Object> vec){
    for (auto v: vec) std::cout << v.getName() << '\n';
}

struct Bar {
	std::string getName() const {
	    return "Bar";
	}
};

struct Foo {
	std::string getName() const {
	    return "Foo";
	}
};

int main(){
	
	std::cout << '\n';
	
	std::vector<Object> vec{Object(Foo()), Object(Bar())};
	
	printName(vec);
	
	std::cout << '\n';

}
