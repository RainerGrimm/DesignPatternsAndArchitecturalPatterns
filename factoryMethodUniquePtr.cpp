#include <iostream>
#include <memory>

// Product
class Window{ 
  public: 
    virtual std::unique_ptr<Window> clone() = 0; 
};

// Concrete Products 
class DefaultWindow: public Window {
  public:
    DefaultWindow() {
      std::cout << "DefaultWindow" << '\n';
    }
  private:
    std::unique_ptr<Window> clone() override { 
      return std::make_unique<DefaultWindow>();
    } 
};

class FancyWindow: public Window {
  public:
    FancyWindow() {
      std::cout << "FancyWindow" << '\n';
    }
  private:
    std::unique_ptr<Window> clone() override { 
      return std::make_unique<FancyWindow>();
    } 
};

// Concrete Creator or Client
auto getNewWindow(std::unique_ptr<Window>& oldWindow) { 
  return oldWindow->clone();
}
  
int main() {

  std::unique_ptr<Window> defaultWindow = std::make_unique<DefaultWindow>();
  std::unique_ptr<Window> fancyWindow = std::make_unique<FancyWindow>();
  
  auto defaultWindow1 = getNewWindow(defaultWindow);
  auto fancyWindow1 = getNewWindow(fancyWindow);
  
}
