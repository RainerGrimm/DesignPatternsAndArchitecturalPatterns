// foo.cpp

#include <string>
#include <utility>
#include <vector>

class Foo {
 public:
    void swap(Foo& rhs) noexcept {
        using std::swap;
        s.swap(rhs.s);
        v.swap(rhs.v);
        swap(i, rhs.i);
    }
 private:
    std::string s{};
 	std::vector<int> v{};
    int i{};
};

int main() {

    Foo foo;
    Foo foo2;
    foo.swap(foo2);
}