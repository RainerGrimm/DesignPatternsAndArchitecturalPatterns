#include <iostream>
#include <vector>
#include <typeinfo>
#include <variant>
#include <string>

template<typename ... Ts> 
struct Overload : Ts ... { 
    using Ts::operator() ...;
};
template<class... Ts> Overload(Ts...) -> Overload<Ts...>;

int main(){
  
    std::cout << '\n';
  
    std::vector<std::variant<char, long, float, int, double, long long>>      
               vecVariant = {5, '2', 5.4, 100ll, 2011l, 3.5f, 2017};

    auto TypeOfIntegral = Overload {                                      
        [](char) { return "char"; },
        [](int) { return "int"; },
        [](unsigned int) { return "unsigned int"; },
        [](long int) { return "long int"; },
        [](long long int) { return "long long int"; },
        [](auto) { return "unknown type"; },
    };
  
    for (auto v : vecVariant) {                                           
        std::cout << std::visit(TypeOfIntegral, v) << '\n';
    }

    std::cout << '\n';

    std::vector<std::variant<std::vector<int>, double, std::string>>     
        vecVariant2 = { 1.5, std::vector<int>{1, 2, 3, 4, 5}, "Hello "};

    auto DisplayMe = Overload {                                           
        [](std::vector<int>& myVec) { 
                for (auto v: myVec) std::cout << v << " ";
                std::cout << '\n'; 
            },
        [](auto& arg) { std::cout << arg << '\n';},
    };

    for (auto v : vecVariant2) {                                         
        std::visit(DisplayMe, v);
    }

    std::cout << '\n';
  
}