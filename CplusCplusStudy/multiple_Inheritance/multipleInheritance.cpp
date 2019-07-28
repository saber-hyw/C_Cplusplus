/**
 * By Yongwu Han
 * 
 * 程序主要用来展现 多重继承构造函数的顺序
 * 
 * 对动物园的大熊猫使用多继承；
 * 有一个ZooAnimal类， 辅助类：Bear(熊) Endangered(濒危灭绝的) ，Panda(大熊猫):继承自Bear和Endangered
 */

#include <iostream>

using namespace std;

// animal
class Animal
{
private:
    /* data */
public:
    Animal(/* args */);
    ~Animal();
};

Animal::Animal(/* args */)
{
    cout << "Animal()" << endl;
}

Animal::~Animal()
{
    cout << "~Animal()" << endl;
}


// 最终基类
class ZooAnimal
{
private:
    /* data */
    string zooAnimalName;
public: 
    // 无初始值
    ZooAnimal();
    // 有初始值
    ZooAnimal(string name);
    ~ZooAnimal();
};

ZooAnimal::ZooAnimal(string name) : zooAnimalName(name)   // 使用初始化列表将值赋给类的成员变量
{
    cout << "ZooAnimal(), zooAnimalName = " << name << endl;
}

ZooAnimal::~ZooAnimal()
{
    cout << "~ZooAnimal()" << endl;
}


// Bear
class Bear: public ZooAnimal
{
private:
    /* data */
    string bearName;
public:
    Bear();
    Bear(string name);  // 构造函数声明只需要形参；这种写法是错误的：Bear(string name): ZooAnimal(name), bearName(name);
    ~Bear();
};

Bear::Bear(string name) : ZooAnimal(name), bearName(name)
{
    cout << "Bear() bearName =" << name << endl;
}

Bear::~Bear()
{
    cout << "~Bear()" << endl;
}


// 濒危类
class Endangered
{
private:
    /* data */
    int endangeredState;
public:
    Endangered(int enState);
    ~Endangered();
};

Endangered::Endangered(int enState) : endangeredState(enState) 
{
    cout << "Endangered(), endangeredState = " << enState << endl;
}

Endangered::~Endangered()
{
    cout << "~Endangered()" << endl;
}


// 大熊猫类使用多继承
class Panda: public Bear, public Endangered
{
private:
    /* data */
    string pandaName;
public:
    Panda(string name);
    ~Panda();
};

Panda::Panda(string name) : Endangered(1), Bear(name), pandaName(name)
{
    cout << "Panda()" << endl;
}

Panda::~Panda()
{
    cout << "~Panda()" << endl;
}


int main()
{

    Panda("lili");

    return 0;
}
