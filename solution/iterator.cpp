#include <iostream>

template<typename T>
class Generator {
    T begin_{};
    T end_{};

public:
    Generator(T begin, T end) : begin_{begin}, end_{end} {}

    class Iterator {
        T value_{};
    public:
        explicit Iterator(T pos) : value_{pos} {}

        T operator*() const { return value_; }

        Iterator& operator++() {
            ++value_;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return value_ != other.value_;
        }
    };

    Iterator begin() const { return Iterator{begin_}; }
    Iterator end() const { return Iterator{end_}; }
};

int main() {
    
    Generator<int> r{-10, 10};
    for (auto v : r) std::cout << v << " ";

}
