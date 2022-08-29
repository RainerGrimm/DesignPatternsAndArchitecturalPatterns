#include <iostream>

// Product
class Window{ 
 public: 
    virtual Window* clone() = 0; 
    virtual ~Window() {};
};

// Concrete Products 
class DefaultWindow: public Window { 
    DefaultWindow* clone() { 
        std::cout << "DefaultWindow" << '\n';
        return new DefaultWindow();
    } 
};

class FancyWindow: public Window { 
    FancyWindow* clone() { 
        std::cout << "FancyWindow" << '\n';
        return new FancyWindow();
    } 
};

// Concrete Creator or Client
Window* getNewWindow(Window& oldWindow) { 
    return oldWindow.clone();
}
  
int main() {

    std::cout << '\n';

    DefaultWindow defaultWindow;
    FancyWindow fancyWindow;
  
    const Window* defaultWindow1 = getNewWindow(defaultWindow);
    const Window* fancyWindow1 = getNewWindow(fancyWindow);
  
    delete defaultWindow1;
    delete fancyWindow1;

    std::cout << '\n';
  
}
