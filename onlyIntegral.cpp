#include <type_traits>

template<typename T,
         typename std::enable_if<std::is_integral<T>::value, T>::type = 0>
T onlyIntegral(T t){
    return t;
}

int main() {

    onlyIntegral(5);
    // onlyIntegral(5.5);

}