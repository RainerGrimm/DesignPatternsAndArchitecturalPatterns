#include <iostream>
#include <map>


int main(){

    std::cout << '\n';
    
    std::map<std::string, int, std::greater<std::string>> myDecreaseMap{{"Grimm", 1}, {"Huber", 2}, {"Meyer", -2}, {"Schmitt", 3}};

    std::cout << "myDecreaseMap: ";
    for(auto m : myDecreaseMap) std::cout << '{' << m.first << ", " << m.second << "}";

    std::cout << "\n\n";

}
