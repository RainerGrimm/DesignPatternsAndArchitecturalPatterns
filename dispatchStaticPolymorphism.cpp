#include <chrono>
#include <iostream>

auto start = std::chrono::steady_clock::now();

void writeElapsedTime(){
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = now - start;
  
    std::cerr << diff.count() << " sec. elapsed: ";
}

template <typename ConcreteMessage>                        
struct MessageSeverity{
  void writeMessage(){                                    
    static_cast<ConcreteMessage*>(this)->writeMessageImplementation();
  }
  void writeMessageImplementation() const {
    std::cerr << "unexpected" << '\n';
  }
};

struct MessageInformation: MessageSeverity<MessageInformation>{
  void writeMessageImplementation() const {              
    std::cerr << "information" << '\n';
  }
};

struct MessageWarning: MessageSeverity<MessageWarning>{
  void writeMessageImplementation() const {               
    std::cerr << "warning" << '\n';
  }
};

struct MessageFatal: MessageSeverity<MessageFatal>{};     

template <typename T>
void writeMessage(T& messServer){                       
	
	writeElapsedTime();                                   
	messServer.writeMessage();                            
	
}

int main(){

    std::cout << '\n';
  
    MessageInformation messInfo;
    writeMessage(messInfo);
    
    MessageWarning messWarn;
    writeMessage(messWarn);

    MessageFatal messFatal;
    writeMessage(messFatal);
  
    std::cout << '\n';

}
