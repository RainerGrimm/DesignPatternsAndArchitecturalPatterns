// from https://en.wikipedia.org/wiki/Substitution_failure_is_not_an_error

#include <iostream>
#include <type_traits>

template <typename T, typename = void>
struct has_typedef_foobar : std::false_type {};

template <typename T>
struct has_typedef_foobar<T, std::void_t<typename T::foobar>> : std::true_type {};

struct foo {
  using foobar = float;
};

int main() {

    std::cout << std::boolalpha << '\n';

    std::cout << "has_typedef_foobar<int>::value: " << has_typedef_foobar<int>::value << '\n';
    std::cout << "has_typedef_foobar<foo>::value: " << has_typedef_foobar<foo>::value << '\n';

    std::cout << '\n';

}