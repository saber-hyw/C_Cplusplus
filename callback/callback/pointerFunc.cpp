#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int sumFunc(int x, int y)
{
    cout<<"x+y = "<< x + y <<endl;
    return  x + y;
}

int multiplicationFunc(int x, int y)
{
    cout<< "x*y = " << x * y <<endl;
    return x * y;
}

// callback 函数申明
int (*callbackFunc)(int, int);

// 传入参数，以及函数指针
void invokeCallBack(const int callbackFunc)
{
    callbackFunc;
}

int main(void)
{
    invokeCallBack(&sumFunc);
    invokeCallBack(&multiplicationFunc);

    return 0;
}