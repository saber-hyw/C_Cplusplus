/**
 * 单例模式:保证一个类仅有一个实例,并提供一个访问它的全局访问点; (最简单的方法)
 * [不能通过类来实例化多个对象; 让类自身保存它唯一的实例;并且提供一个全局访问该实例的方法;]
 * 创建方法:
 * (1) 构造方法私有化(private); 这就堵死了外界利用new来创建此类的实例; (构造)
 * (2) 创建一个静态成员函数, 对外提供唯一的全局访问点, 用于获取本类的唯一实例; (public 静态函数)
 *     补充: 在public 静态函数里面,判断实例是否存在;如果不存在,则new一个新实例,否则返回已有的实例;
 * 使用方法:
 * 一般使用方法是用 ClassName::GetInstance()-> 函数; (或ClassName::GetInstance(). 函数;
 * 
 **/

#include <iostream>

using namespace std;

class Singleton {
private:
      Singleton();
      ~Singleton();      
public:
      static Singleton* GetInstance();   // 定义一个返回指针变量的函数
private:
      static Singleton *pInstance;
};


// implement (实现)
Singleton *Singleton::pInstance = NULL;

Singleton::Singleton() {
      cout << "Singleton()" << endl;
}

Singleton::~Singleton() {
      cout << "~Singleton()" << endl;
}

// function of GetInstance to return *pInstance;
Singleton *Singleton::GetInstance() {
      if (NULL == pInstance) {
            pInstance = new Singleton();
      }
      
      return pInstance;
}

int main(int argc, char const *argv[])
{
      // code of verification
      Singleton *s1 = Singleton::GetInstance();  // 因为之前实现的时候定义的是指针,因此这里也需要定义为指针;
      Singleton *s2 = Singleton::GetInstance();  
      if (s1 == s2) {
            // 如果s1 = s2 说明, 从实例中得到的是同一个指针; 证明是同一个实例,简单的单例模式OK;
            cout << "The pInstance is consistency(一致)" << endl;
      } else {
            cout << "The pInstance is not consistency" << endl; 
      }

      return 0;
}


