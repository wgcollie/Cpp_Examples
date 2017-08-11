#include <iostream>
#include <vector>
#include <initializer_list>
#include <string>

class B {
public:
    void showObjectInfo(std::string msg)
    {
        std::cout << "Class B: " << msg << "\n";
        std::cout << "    address: " << this << "\n";
        std::cout << "    member data address: " << &data << "\n";
        std::cout << "    member data (address)values: " << "\n";
        for (auto &e : data) {
            std::cout << "        ";
            std::cout << "(" << &e << ")" << e << "\n";
        };
        
    };
    B():data{0}{};
    B(std::initializer_list<int> dd):data{dd}{};
    B(const B& b) = delete;             //We only want move copy
    B& operator=(const B& b) = delete;  //and move assignment
private:
    std::vector<int> data;
};

class A {
public:
    void capture(B bExternal) {bb = std::move(bExternal);};
    void showObjectInfo(std::string msg)
    { 
        std::cout << "Class A: " << msg << "\n";
        std::cout << "    address: " << this << "\n";
        std::cout << "    member bb address: " << &bb << "\n";
        bb.showObjectInfo("Class A attribute bb");
    };
private:
    B bb;
};
int main() 
{
    A aa;
    B bb{1,2,3,4}; //bb is an lvalue

    std::cout << "Part 1: Initial states\n";
    bb.showObjectInfo("bb");
    aa.showObjectInfo("aa");
    std::cout << "\n";

    aa.capture(bb);

    std::cout << "Part 2: After capture\n";
    bb.showObjectInfo("bb");
    aa.showObjectInfo("aa");
    std::cout << "\n";
}
