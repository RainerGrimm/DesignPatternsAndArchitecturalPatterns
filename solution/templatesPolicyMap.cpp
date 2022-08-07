#include <iostream>
#include <map>
#include <unordered_map>

struct MyInt{
    explicit MyInt(int v):val(v){}
    int val;
};

struct MyHash{
    std::size_t operator()(MyInt m) const {
        std::hash<int> hashVal;
        return hashVal(m.val);
    }
};

struct MyEqual{
    bool operator () (const MyInt& fir, const MyInt& sec) const {
        return fir.val == sec.val;
    }
};

struct MySmaller{
    bool operator () (const MyInt& fir, const MyInt& sec) const {
        return fir.val < sec.val;
    }
    
};

std::ostream& operator << (std::ostream& strm, const MyInt& myIn){
    strm << "MyInt(" << myIn.val << ")";
    return strm;
}

int main(){

    std::cout << '\n';

    typedef std::unordered_map<MyInt, int, MyHash, MyEqual> MyUnorderedMap;

    std::cout << "MyUnorderedMap: ";
    MyUnorderedMap myMap{{MyInt(-2), -2}, {MyInt(-1), -1}, {MyInt(0), 0}, {MyInt(1), 1}};

    for(auto m : myMap) std::cout << '{' << m.first << ", " << m.second << "}";

    std::cout << '\n';
    
    typedef std::map<MyInt, int, MySmaller> MyOrderedMap;
    
    std::cout << "MyOrderedMap: ";
    MyOrderedMap myMap2{{MyInt(-2), -2}, {MyInt(-1), -1}, {MyInt(0), 0}, {MyInt(1), 1}};
    
    for(auto m : myMap2) std::cout << '{' << m.first << ", " << m.second << "}";

    std::cout << "\n\n";

}
