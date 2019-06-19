#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int val1, val2, val3, val4;
    val1 = 19.99 + 11.99;  // 先相加=31.98, 再将double类型转为int;
    val2 = (int) 19.99 + (int) 11.99;
    val3 = int (19.99) + int (11.99);
    cout << "val1 = " << val1 <<endl;
    cout << "val2 = " << val2 <<endl;
    cout << "val3 = " << val3 <<endl;

    // add
    val4 = 19 + 11.99;      // double 转int, 会先将11.99转为int，再和int 19相加；
    cout << "val4 = " << val4 <<endl;

    // converts char type
    char ch = {'z'};
    cout << "int (ch) = " << int (ch) << endl;
    cout << "static_cast<int> ch = " << static_cast<int> (ch) <<endl;


    // 关于缩窄：
    const int code = 6665;
    char c = {code};  // warning: overflow in implicit constant conversion; 越界，警告，但是可以编译通过；
    int code1 = 66;
    char c1 = {code1};   // 赋值给c1的需要是一个常量,不然值会变
    int x = 66;
    x = 65;
    char c2 = x;   // ???:

    // auto 更适用于STL模板
    vector<double> scores;
    vector<double>::iterator pv = scores.begin(); // 这是C++98的写法
    auto pv_11 = scores.begin();                  // 这是C++11的写法, 简单的来说更方便了

    // array 
    short things[] = {1, 3, 4, 6};
    int num_elements = sizeof things / sizeof(short);
    cout << "sizeof things / sizeof(short) = " << sizeof things / sizeof(short) << endl;

    return 0;
}