/**
 * By yongwu Han
 * 主要用于探究C++ String 实现：
 * (1) 默认构造函数, const char*;
 * (2) 拷贝构造函数, const string &str; 原理是调用默认构造函数初始化，获得string data，然后用strcpy来完成数据的复制；
 * (3) 赋值函数: new char[], strcpy, return *this;
 * (4) 析构函数: delete ptr;
 * 
 * 以下为面试题的例子：
 *  
 **/

#include <iostream>
#include <string.h> /* for strlen() function Note: strlen(const char *_Str), 参数可以是指针str和字符串. 
                    also for strcopy() */                

class myString
{
public:
    myString(const char *str = NULL);           // 普通构造函数,默认字符串为NULL
    myString(const myString &str);              // 拷贝构造函数
    ~ myString(void);                           // 析构函数
    myString &operator=(const myString &str);   // 赋值函数
    char operator[](int n) const;               // 重载运算符[]
    // myString &operator+(const myString& lhs, const myString& rhs) 
    const char *c_str() const;                  // 返回一个常量指针，且不能修改类成员变量

    void showData();
    int size() const;
private:
    char *m_data;                           // 用于保存string字符串的内容
};

// 普通构造函数
myString::myString(const char *str) {
    std::cout << "default constructor "<< std::endl;
    
    if (NULL == str) {
        // 需要创建一个空字符，保存值为'\0';
        m_data = new char[1];  // new 一个长度为1的char数组, 将指针赋给m_data;
        *m_data = '\0';        // 将值(*m_data)赋值为空字符'\0'
    } else {
        // 保存*str的值到 *m_data
        m_data = new char[strlen(str)];
        strcpy(m_data, str);
        std::cout << "m_data = " << m_data << std::endl;
    }
}

// 析构函数
myString::~myString() {
    if (m_data) {
        delete []m_data;  // 因为使用了new array[], 因此需要有对应的 delete []m_data;
        m_data = NULL;
    }
}

// 拷贝构造函数
myString::myString(const myString &str) {
    std::cout << "copy constructor "<< std::endl;
    // 就是strcpy
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

// 赋值函数: 重载运算符"="; 用的是引用
myString &myString::operator=(const myString &str) {
    std::cout << "operator= "<< std::endl;

    // 调用普通构造函数，然后strcpy
    if (this != &str) {
        m_data = new char[strlen(str.m_data) + 1];
        strcpy(m_data, str.m_data);
    }

    return *this;  // 取this指针指向的myString对象返回
}

// 重载运算符 "[]", 用于返回特定的字符
char myString::operator[](int n) const {
    if (n < 0 || n > size()) {
        return m_data[0];
    }
    if (m_data) {
        return m_data[n];
    }
}

// 重载运算符 "+"
// C 库函数 char *strcat(char *dest, const char *src) 把 src 所指向的字符串追加到 dest 所指向的字符串的结尾。
// myString operator+(const myString& lhs, const myString& rhs) {
// 	myString res;
// 	int len = lhs.size() + rhs.size();
// 	res.m_data = new char[len + 1];
// 	strcpy(res.m_data, lhs.m_data);
// 	strcat(res.m_data, rhs.m_data);
// 	return res;
// }


// 转成c字符串
const char* myString::c_str() const {
    return m_data;
}

int myString::size() const {
    return strlen(m_data);
}

void myString::showData() {
    std::cout << "string = " << *m_data << std::endl;
}

int main() 
{
    myString hyw1("hyw");
    myString hyw2 = hyw1;
    hyw2 = "hyw2";

    const char *hyw = "hyw";

    std::cout << "strlen = " << strlen(hyw) << std::endl;
    std::cout << "strlen = " << strlen("hyw") << std::endl;
    std::cout << "sizeof = " << sizeof(hyw) << std::endl;  // 打印的是指针的字节大小
    std::cout << "sizeof = " << sizeof(*hyw) << std::endl; // 打印的才是字符串的字符个数，包含'\0'



    return 0;
}