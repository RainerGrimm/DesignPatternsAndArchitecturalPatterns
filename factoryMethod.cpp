#include <iostream>

// Product
class Window{ 
  public: 
    virtual Window* clone() = 0; 
    virtual ~Window() {};
};

// Concrete Products 
class DefaultWindow: public Window { 
  public:
    DefaultWindow() {
      std::cout << "DefaultWindow" << '\n';
    }
  private:
    DefaultWindow* clone() { 
      return new DefaultWindow();
    } 
};

class FancyWindow: public Window { 
  public:
    FancyWindow() {
	  std::cout << "FancyWindow" << '\n';
	}
  private:
    FancyWindow* clone() { 
      return new FancyWindow();
    } 
};

// Concrete Creator or Client
Window* getNewWindow(Window& oldWindow) { 
  return oldWindow.clone();
}
  
int main(){

  DefaultWindow defaultWindow;
  FancyWindow fancyWindow;
  
  const Window* defaultWindow1 = getNewWindow(defaultWindow);
  const Window* fancyWindow1 = getNewWindow(fancyWindow);
  
  delete defaultWindow1;
  delete fancyWindow1;
  
}
