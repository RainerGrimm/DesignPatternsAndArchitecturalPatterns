#include <iostream>
#include <memory>
#include <string>
#include <typeinfo>
#include <vector>

struct Object{
   std::string getTypeName() const { return _inner->getTypeName(); }
   struct Concept{
      using ptr = std::unique_ptr<Concept>;
      virtual std::string getTypeName() const = 0;
   };
   template <typename T> struct Model : Concept{
      std::string getTypeName() const override { return typeid(T).name(); }
   };
private:
   typename Concept::ptr _inner;
};

	

template <typename T>
void printType(T&& t){
    std::cout << t.getTypeName() << '\n';
}

class Test{};

int main(){
   
   printType(Object::Model<int>{});
   printType(Object::Model<double>{});
   printType(Object::Model<void>{});
   printType(Object::Model<Test>{});
   printType(Object::Model<Object>{});
   printType(Object::Model<long long>{});
   printType(Object::Model<std::string>{});
   printType(Object::Model<std::vector<int>>{});   
    
}
