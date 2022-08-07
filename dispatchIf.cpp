#include <chrono>
#include <iostream>

enum class MessageSeverity{                                 
    information,
    warning,
    fatal,
};

auto start = std::chrono::steady_clock::now();              

void writeElapsedTime(){                                   
    auto now = std::chrono::steady_clock::now();            
    std::chrono::duration<double> diff = now - start;
  
    std::cerr << diff.count() << " sec. elapsed: ";
}

void writeInformation(){ std::cerr << "information" << '\n'; }
void writeWarning(){ std::cerr << "warning" << '\n'; }
void writeUnexpected(){ std::cerr << "unexpected" << '\n'; }

void writeMessage(MessageSeverity messServer){               
	
    writeElapsedTime();                                      
	
    if (MessageSeverity::information == messServer){
	    writeInformation();
    }
    else if (MessageSeverity::warning == messServer){
	    writeWarning();
    }
    else{
	    writeUnexpected();
    }
  
}

int main(){

    std::cout << '\n';
  
    writeMessage(MessageSeverity::information);
    writeMessage(MessageSeverity::warning);
    writeMessage(MessageSeverity::fatal);

    std::cout << '\n';

}
