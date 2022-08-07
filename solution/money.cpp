#include <iostream>
#include <unordered_set>

class Money {
 public:
    Money() = default;
    Money(double a): amt(a) {}

    bool operator == (const Money& ) const = default;
    double getAmount() const {
        return amt;
    }
 private:
    const double amt{0.0};
};

template<>
struct std::hash<Money> {
    std::size_t operator()(Money const& mon) const noexcept {
        return std::hash<double>{}(mon.getAmount());
    }
};

int main() {

    std::cout << std::boolalpha << '\n';

    Money money1(0.0);
    Money money2;

    std::cout << "money1 == money2: " << (money1 == money2) << '\n';

    std::unordered_set<Money> myMoneySet{money1 , money2};
    for(auto mon: myMoneySet) std::cout << "mon.getAmount(): " << mon.getAmount() << '\n';

    std::cout << '\n';

}