#include <iostream>

using namespace std;

class TestStatic
{
public:
      TestStatic();
      ~TestStatic();  // 构造函数和析构函数,不能是private,不然不能够创建对象;  在单例模式下,构造函数必须要是私有才能控制只有一个类对象;
public:
      static int getObjectCounts();   // 静态函数,可以被直接调用,不需要类对象;如TestStatic::getObjectCounts()
private:
      static int objectCounts;    // (4)
public:
      static int objectPublicCounts;
};

int TestStatic::objectCounts = 0;   // (1)
int TestStatic::objectPublicCounts = 0;

TestStatic::TestStatic() {
      objectCounts ++;
}

TestStatic::~TestStatic() {
      
}

int TestStatic::getObjectCounts() {
      cout << "Now Object Counts = " << objectCounts << endl;
      
      return objectCounts;
}

int main(int argc, char const *argv[])
{
      /* code */
      cout << "get public static variable = " << TestStatic::objectPublicCounts << endl;  // (5)

      cout << "The object counts before create = " << TestStatic::getObjectCounts() << endl;

      TestStatic T1;
      T1.getObjectCounts();
      cout << "public static variable = " << T1.objectPublicCounts << endl;
      TestStatic T2;

      cout << "The object counts after create = " << TestStatic::getObjectCounts() << endl;

      return 0;
}


/**
 *关于static, 实践的理解: 
 *(1) static variable(变量) 在类的内部申明(private和public都可以), 
 *在类外使用[int TestStatic::objectCounts = 0;] 这种形式进行初始化;
 *(2) static 成员变量,只拥有一个数据副本, 不论这个类创建多少个对象; static 变量为所有对象共享;
 *(3) static 成员函数: 只能访问静态成员变量; 
 *    静态成员函数,可以直接被调用[TestStatic::getObjectCounts()], 不需要类对象;
 *    普通成员函数, 可以访问过静态成员函数和静态成员变量;
 * 
 * 
 * */

/*https://www.jianshu.com/p/7034c4dbc496*/


/**
 * 补充:
 * (4)静态数据成员遵从public private protected访问规则;
 * (5)访问规则允许的情况下:静态数据成员,可以直接使用 类名+作用域符(::) 直接访问; 如:[类名>::<变量名>]
 * (6)静态成员函数, 没有this指针;
 * (7)静态成员函数, 可以使用 [<类名>::<函数名>] 访问，也可由类对象使用(. 或 ->)访问
 * */



/**
 * This is import : https://zh.cppreference.com/w/cpp/language/static
 *
 * 
 **/