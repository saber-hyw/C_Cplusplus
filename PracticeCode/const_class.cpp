#include <iostream>

using namespace std;

// using c++11 standard
class CTest11
{
public:
    static const int a = 3; // Ok in C++11
    static int b = 4;       // C++11 禁止在类中初始化非const静态成员
    const int c = 5;        // Ok in C++11
    int d = 6;              // Ok in C++11

    static int e;           // 禁止初始化，但是可以定义；同单例模式的实现，仅仅只是定义一个静态变量；

public:
    CTest11() :c(0) { }     // Ok in C++11
};

int main()
{
    CTest11 testObj;
    cout << testObj.a << testObj.b << testObj.c << testObj.d << endl;
    return 0;
}