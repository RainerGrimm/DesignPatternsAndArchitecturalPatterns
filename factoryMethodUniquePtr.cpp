#include <iostream>
#include <memory>

// Product
class Window{ 
 public: 
    virtual std::unique_ptr<Window> clone() = 0; 
};

// Concrete Products 
class DefaultWindow: public Window {
    std::unique_ptr<Window> clone() override { 
        std::cout << "DefaultWindow" << '\n';
        return std::make_unique<DefaultWindow>();
    } 
};

class FancyWindow: public Window {
    std::unique_ptr<Window> clone() override { 
        std::cout << "FancyWindow" << '\n';
        return std::make_unique<FancyWindow>();
    } 
};

// Concrete Creator or Client
auto getNewWindow(std::unique_ptr<Window>& oldWindow) { 
    return oldWindow->clone();
}
  
int main() {

    std::cout << '\n';

    std::unique_ptr<Window> defaultWindow = std::make_unique<DefaultWindow>();
    std::unique_ptr<Window> fancyWindow = std::make_unique<FancyWindow>();
  
    const auto defaultWindow1 = getNewWindow(defaultWindow);
    const auto fancyWindow1 = getNewWindow(fancyWindow);

    std::cout << '\n';
  
}
