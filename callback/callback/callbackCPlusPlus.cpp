#include<iostream>
using std::cout;
using std::endl;

void Sum(int a, int b) 
{
    int c = a + b;
    cout << "Sum = "<< c <<endl;
}

typedef void (*FuncCallBack)(int, int);

void GetCallBack(const int i, FuncCallBack cb)
{
    if (1 == i)
    {
        cb(3, 4);
    }
}

int main(void)
{
    GetCallBack(1, &Sum);
}