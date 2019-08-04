#include <iostream>

using std::cout;
using std::endl;


class Time
{
private:
    /* data */
    int hours;
    int minutes;
public:
    Time(/* args */);
    Time(int h, int m = 0);
    ~Time();

    // 创建拷贝构造函数
    Time(const Time &T);

    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    Time Sum(const Time &T) const;
    // 返回对象的引用
    Time &sum_1(const Time &T);
    void show() const;
};

Time::Time(/* args */)
{
    minutes = hours = 0;
}

Time::Time(int h, int m) {
    hours = h;
    minutes = m;
    cout << "constructor " << endl;
}

Time::Time(const Time &T) {
    cout << "copy constructor" << endl;
    hours = T.hours;
}

Time::~Time()
{
    cout << "destructor~" << endl;
}

void Time::AddMin(int m) {
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h) {
    hours += h;
}

void Time::Reset(int h, int m) {
    hours = h;
    minutes = m;
}

Time Time::Sum(const Time &T) const {
    Time sum;
    sum.minutes = minutes + T.minutes;  // 对象已有的时间+新加的时间
    sum.hours = hours + T.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum; // 函数返回临时对象，意味着程序将在删除sum对象之前构造它的拷贝，调用函数将得到该拷贝；
}

Time &Time::sum_1(const Time &T) {
    hours = T.hours + hours;

    return *this;
}

void Time::show() const {
    cout << hours <<" hours, " << minutes << " minutes" << endl;
}

int main()
{
    Time a(1, 0);
    a.show();

    Time a1(10, 0);
    a1.show();

    Time a2 = a1.sum_1(a);  // 这里会调用 拷贝构造函数；
    a2.show();

    return 0;
}
