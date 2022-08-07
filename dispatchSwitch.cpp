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

void writeMessage(MessageSeverity messSever){
	
    writeElapsedTime();

    switch(messSever){
        case MessageSeverity::information:
            writeInformation();
            break;
        case MessageSeverity::warning:
            writeWarning();
            break;
        default:
            writeUnexpected();
            break;
  }
  
}

int main(){

    std::cout << '\n';
  
    writeMessage(MessageSeverity::information);
    writeMessage(MessageSeverity::warning);
    writeMessage(MessageSeverity::fatal);

    std::cout << '\n';

}
