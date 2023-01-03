#include <iostream>
#include <type_traits>

template <typename T>
void getPrimaryTypeCategory(){

  std::cout << std::boolalpha << '\n';

  std::cout << "std::is_void<T>::value: " << std::is_void<T>::value << '\n';
  std::cout << "std::is_integral<T>::value: " << std::is_integral<T>::value << '\n';
  std::cout << "std::is_floating_point<T>::value: " << std::is_floating_point<T>::value << '\n';
  std::cout << "std::is_array<T>::value: " << std::is_array<T>::value << '\n';
  std::cout << "std::is_pointer<T>::value: " << std::is_pointer<T>::value << '\n';
  std::cout << "std::is_null_pointer<T>::value: " << std::is_null_pointer<T>::value << '\n';
  std::cout << "std::is_member_object_pointer<T>::value: " << std::is_member_object_pointer<T>::value << '\n';
  std::cout << "std::is_member_function_pointer<T>::value: " << std::is_member_function_pointer<T>::value << '\n';
  std::cout << "std::is_enum<T>::value: " << std::is_enum<T>::value << '\n';
  std::cout << "std::is_union<T>::value: " << std::is_union<T>::value << '\n';
  std::cout << "std::is_class<T>::value: " << std::is_class<T>::value << '\n';
  std::cout << "std::is_function<T>::value: " << std::is_function<T>::value << '\n';
  std::cout << "std::is_lvalue_reference<T>::value: " << std::is_lvalue_reference<T>::value << '\n';
  std::cout << "std::is_rvalue_reference<T>::value: " << std::is_rvalue_reference<T>::value << '\n';

  std::cout << '\n';

}

int main(){
    getPrimaryTypeCategory<int&>();
}
