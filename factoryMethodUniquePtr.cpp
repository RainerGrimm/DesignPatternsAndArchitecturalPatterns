#include <iostream>
#include <memory>

// Product
class Window{ 
 public: 
    virtual std::unique_ptr<Window> create() { 
        std::cout << "Create Window" << '\n';
        return std::make_unique<Window>();
    } 
};

// Concrete Products 
class DefaultWindow: public Window {
    std::unique_ptr<Window> create() override { 
        std::cout << "Create DefaultWindow" << '\n';
        return std::make_unique<DefaultWindow>();
    } 
};

class FancyWindow: public Window {
    std::unique_ptr<Window> create() override { 
        std::cout << "Create FancyWindow" << '\n';
        return std::make_unique<FancyWindow>();
    } 
};

// Concrete Creator or Client
auto createWindow(std::unique_ptr<Window>& oldWindow) { 
    return oldWindow->create();
}
  
int main() {

    std::cout << '\n';

    std::unique_ptr<Window> window = std::make_unique<Window>();
    std::unique_ptr<Window> defaultWindow = std::make_unique<DefaultWindow>();
    std::unique_ptr<Window> fancyWindow = std::make_unique<FancyWindow>();
  
    const auto window1 = createWindow(window);
    const auto defaultWindow1 = createWindow(defaultWindow);
    const auto fancyWindow1 = createWindow(fancyWindow);

    std::cout << '\n';
  
}
