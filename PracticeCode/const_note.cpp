#include <iostream>

using namespace std;

// const 修饰函数
const int functionA() { 
    int a = 10;
    return a; 
}
const int *functionB() {
    int b = 10;
    int *c = &b;
    return c;
} 

int main()
{
    int const value_1 = {1};
    const int  value_2 = {2};

    const int arrayVal_1[3] = {1, 2, 3};
    int const arrayVal_2[3] = {2, 4, 5};

    // ==> 对于类似这些基本数据类型，修饰符const可以用在类型说明符前，也可以用在类型说明符后;
    // ==> 即：基本数据类型对于const修饰符来说是透明的；（隐去基本数据类型，发现上下两种写法是一样的；）

    // test: 测试一下 符号“&”的 具体含义和作用；
    int a;        // a is an integer
    int *aPtr;    // is a pointer to an integer
    a = 10;
    aPtr = &a;    // assign the address of a to the pointer variable;

    // 打印a的值和内存地址；打印指针aPtr的值和地址
    cout<< "value of a = " << a << endl;
    cout<< "address of a = " << aPtr << endl;   // 这里可以直接打印出地址
    // cout<< "address of a = " << static_cast<void*> (aPtr); // 也可以使用这种方式，显示的告诉cout，需要输出指针地址；
    // 如果是打印字符串的话，必须要使用类型转换；

    cout<<"a = " <<a <<" *aPtr = " <<*aPtr<< endl;

    cout<<"&*aPtr = " <<&*aPtr <<endl;  // 这里是打印a的指针地址

    cout<<"*&aPtr = " <<*&aPtr <<endl;  // 这里不清楚是什么用法？？？？？？



    // const 修饰函数返回值；
    int aa = functionA()++;
    cout<< "aa = " << aa <<endl;

    return 0;
}