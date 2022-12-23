// decoratorFrame.cpp (based on https://en.wikipedia.org/wiki/Decorator_pattern)

#include <iostream>
#include <string>

struct Shape{
  virtual std::string GetName() const = 0;
  virtual ~Shape() = default;
};

class Circle : public Shape{
public:
  std::string GetName() const override{
    return std::string("A circle of radius ") + std::to_string(radius);
  }
  double radius = 10.0;
};

class ColoredShape : public Shape{
  std::string color;
  Shape& shape;
public:
  ColoredShape(std::string c, Shape& s): color{c}, shape{s} {}
  std::string GetName() const override{
    return shape.GetName() + std::string(" which is coloured ") + color;
  }
};

class FramedShape : public Shape{
  Shape& shape;
public:
  FramedShape(Shape& s): shape{s} {}
  std::string GetName() const override{
    return shape.GetName() + std::string(" and has a frame");
  }
};

int main(){

  Circle circle;
  ColoredShape coloredShape("red", circle);
  FramedShape framedShape1(circle);
  FramedShape framedShape2(coloredShape);
  
  std::cout << circle.GetName() << '\n';
  std::cout << coloredShape.GetName() << '\n';
  std::cout << framedShape1.GetName() << '\n';
  std::cout << framedShape2.GetName() << '\n';

}