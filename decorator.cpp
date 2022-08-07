#include <iostream>
#include <string>

struct Shape{
  virtual std::string str() = 0;
};

class Circle : public Shape{
  float radius = 10.0f;
  
public:
  std::string str() override{
    return std::string("A circle of radius ") + std::to_string(radius);
  }
};

class ColoredShape : public Shape{
  std::string color;
  Shape& shape;
public:
  ColoredShape(std::string c, Shape& s): color{c}, shape{s} {}
  std::string str() override{
    return shape.str() + std::string(" which is coloured ") + color;
  }
};

int main(){

  Circle circle;
  ColoredShape coloredShape("red", circle);
  
  std::cout << circle.str() << '\n';
  std::cout << coloredShape.str() << '\n';

}