/**
 * 程序目的：为了熟悉operator操作符重载
 * (1) 函数只是单纯的加小时
 * (2) 重载 操作符‘*’，*操作符两边的数据类型不一致
 */

#include <iostream>

using std::cout;
using std::endl;

class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);     // 不能都等于0，不然会和前一个默认的构造函数一样；在构造对象的时候，编译器区分不了；
    ~Time();

    // 成员函数方式的重载运算符*
    Time operator*(double m) const;

    // 友元函数的方式重载运算符*
    friend Time operator*(double m, const Time &t);

    void show() const;
};

Time::Time()
{
    minutes = hours = 0;
}

Time::Time(int h, int m) {
    hours = h;
    minutes = m;
    cout << "constructor " << endl;
}

Time::~Time()
{
    cout << "destructor~" << endl;
}

Time Time::operator*(double m) const {  // 使用const保护原对象数据不被修改
    Time t;
    t.hours = hours * m;
    return t;
}

// 没有限定符Time:: 和 friend 关键字；
// 其实，友元函数在一定条件下，可以翻转操作数的顺序；
Time operator*(double m, const Time &t) {
    Time mt;
    // 第一种写法
    mt.hours = m * t.hours;
    return mt;
    /**
     * 另外一种写法, 以下这种调用成员重载函数的方法，可以将友元函数编写为非友元函数.
     * 
     * 让成员函数来处理私有值，因此不必是友元。然而，将该版本作为友元也是一个好主意。
     * 最重要的是，它将该作为正式类接口的组成部分。其次，如果以后发现需要函数直接访问私有数据， 
     * 则只要修改函数定义即可，而不必修改类原型。
     */
    // return t.operator*(m);
}

void Time::show() const {
    cout << hours <<" hours, " << minutes << " minutes" << endl;
}

int main()
{
    Time t(10, 10);
    Time t_1;
    t_1 = t * 2.75;
    t_1.show();

    Time t_2;
    t_2 = 2.75 * t;
    t_2.show();

    return 0;
}
