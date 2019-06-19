#include <iostream>
 
using namespace std;
 
class Box
{
   public:
      static int objectCount;
      // 构造函数定义
      Box(double l, double b, double h);
      ~Box();
      double Volume();
      static int getCount();
   private:
      double length;     // 长度
      double breadth;    // 宽度
      double height;     // 高度
};


// ------------------------------------------------------------------------------------------------------------------------

// 初始化类 Box 的静态成员
int Box::objectCount = 0;

Box::Box(double l = 2.0, double b = 2.0, double h = 2.0) {
    cout <<"Constructor called." << endl;

    length = l;
    breadth = b;
    height = h;

    // 每次创建对象时增加 1 ==> 无论创建多少个类对象,类的静态成员只有一个副本;
    objectCount++;
}

Box::~Box() {
   
}

double Box::Volume()
{
   cout<< "length * breadth * height = " << length * breadth * height << endl;
    return length * breadth * height;
}

int Box::getCount() {
   return objectCount;
}


// ----------------------------------------main---------------------------------------------- 
int main(void)
{
   // 在创建对象之前, 输出对象的总数;
   cout<< "Before create object, counts = " << Box::getCount() << endl;

   Box box1(3.3, 1.2, 1.5);    // 声明 box1
   Box box2(8.5, 6.0, 2.0);    // 声明 box2

   // 在创建对象之后, 输出对象的总数;
   cout<< "After create object, counts = " << Box::getCount() << endl;

   // 输出对象的总数
   cout << "Total objects: " << Box::objectCount << endl;
 
   return 0;
}


// 静态成员变量: (1) 常规的使用和声明格式.  声明:static objectCount; 初始化:[int Box::objectCount = 0]
//             (2) 如果使用了单例模式, 可以使用 [getInstance()->xx] 的方法来使用成员变量或是访问成员函数; 



/**
 * static 关键字;
 * 申明类的成员变量为静态时, 这意味着无论创建多少个类的对象,静态成员都只有一个副本;
 * 静态成员,在类的所有对象中是共享的; 
 * 如果不存在其他的初始化语句,在创建第一个对象时,所有的静态数据都会被初始化为零;
 * 
 * 静态函数的声明和初始化:
 * (1) 声明: 放在类中;
 * (2) 初始化: 放在类的外部, 通过使用范围解析运算符::来重新声明静态变量,从而对它进行初始化;
 * 如: 
 * // 初始化类 Box 的静态成员
 * int Box::objectCount = 0; 
 * 
 **/

/*http://www.runoob.com/cplusplus/cpp-static-members.html*/