
// #include <iostream>
// #include <assert.h>
// using namespace std;

// typedef void (*FPtr)(void);

// class Test
// {
// public:
//     // 友元函数作为回调函数 friend方式实现, 因为callBackFun默认有一个const Test* 的指针
//     friend void callBackFun(void);
// };

// void callBackFun(void) { cout << "CallBack Function!";}



// void Fun(FPtr ptr)
// {
//     (*ptr)();  // it`s also right: ptr();
// }

// int main(void)
// {
//     Fun(callBackFun); 

//     return 0;
// }




// #include<iostream> 
// using namespace std;
// class A {
// public:
//     static void callback()  //类的成员函数作为回调函数 static方式实现  
//     {  
//         cout<< "callback" <<endl;
//     } 
// }; 

// typedef void (*CallbackFun)();

// void functionCall(CallbackFun pCallback) {
//     (*pCallback)();
// } 

// int main() { 
//     CallbackFun pf;
//     pf = A::callback;  
//     functionCall(pf);
//     return 0;
// }



// 还可以把functionCall函数设为类的成员函数：
#include<iostream> 
using namespace std;

typedef void (*CallbackFun)();

class A {
public:
    static void callback()  //类的成员函数作为回调函数 static方式实现  
    {  
        cout<< "callback" <<endl;
    } 

    void functionCall(CallbackFun pCallback) {
        (*pCallback)();
    } 
}; 

int main() { 
    CallbackFun pf;

    A a;
    pf = A::callback;  
    a.functionCall(pf);
    return 0;
}

// #include<iostream> using namespace std; class A { public:    static void callback()  //类的成员函数作为回调函数 static方式实现  {   cout<<"回调函数开始执行了！"<<endl;  }  void f(void (*p)())  {   p();

//  } };

// int main() {  A a;  void (*p)();  p=A::callback;  a.f(p);  return 0; }