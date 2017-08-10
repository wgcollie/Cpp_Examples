#include <iostream>
#include <vector>
#include <initializer_list>

class A {
public:
    A(std::size_t s):x(s){}; //Note: use () instead of {} initilizer
    A(std::initializer_list<int> aList):x{aList}{};
    auto size() {return x.size();};
    void objectInfo() 
    {
        std::cout << "Class A:\n";
        std::cout << "    address: " << this << "\n";
        std::cout << "    member x address: " << &x << "\n";
        std::cout << "    member x values: (" << "\n";
        for (auto &e : x) {
            std::cout << "(" << &e << ")" << e << "\n";
        };
    }; 
private:
    std::vector<int> x;
};

int main()
{
    A aa1{1,2,3,4};
    A aa2(aa1.size());  //Note: use () instead of {} initilizer
    A aa3(aa1.size());

    std::cout << "Part 1: Initial Values.\n";
    aa1.objectInfo();
    aa2.objectInfo();
    aa3.objectInfo();
    std::cout << "\n";

    std::cout << "Part 2: Copy an object.\n";
    aa2 = aa1;
    aa1.objectInfo();
    aa2.objectInfo();
    std::cout << "\n";

    std::cout << "Part 3: Move an object.\n";
    aa3 = std::move(aa1);
    aa1.objectInfo();
    aa3.objectInfo();
    std::cout << "\n";
}
