#include <iostream>
#include <memory>
#include <utility>

struct MyInt{

  MyInt(int i):i_(i){}

  ~MyInt(){
    std::cout << "Good bye from " << i_ << '\n';
  }

  int i_;

};


int main(){

  std::cout << '\n';

  std::unique_ptr<MyInt> uniquePtr1{ new MyInt(1998) };

  {
    std::unique_ptr<MyInt> localPtr{ new MyInt(2003) };
  }

  std::cout << '\n';

}
