#include <QCoreApplication>

// shared_ptr,C++11
#include <memory>
// c++11
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>


struct Base
{
    Base() {std::cout << "Base::Base()\n";}

    //此处非虚构函数
    ~Base() {std::cout <<  "Base::~Base()\n";}
};

struct Derived: public Base
{
    Derived() {std::cout << "Derived::Derived()\n";}
    ~Derived() {std::cout << "Derived::~Derived()\n";}
};

void thr(std::shared_ptr<Base> ptr)
{
    // 阻塞当前线程一秒
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::shared_ptr<Base> lp = ptr; // 线程安全，虽然自增共享的 use_count
    {
        static
    }

}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
