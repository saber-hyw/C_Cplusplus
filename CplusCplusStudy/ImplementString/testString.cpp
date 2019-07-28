#include <iostream>
#include <string.h>  // C include library; for strlen() strcpy();

class myString  {
private:
    char *m_data;
public:
    // 普通构造函数
    myString(const char *str = NULL);
    // 拷贝构造函数：自身类类型的引用+有默认值的参数
    myString(const myString &str);
    // 析构函数
    ~myString();
    // 赋值函数: 重载运算符"="
    myString &operator=(const myString &str);

    // test
    void showstr();
};

myString::myString(const char *str) {
    std::cout << "constructor" <<std::endl;
    if (NULL == str) {
        m_data = new char[1];
        *m_data = '\0';
    } else {
        m_data = new char[strlen(str) + 1];
        strcpy(m_data, str);
    }
}

// 使用普通构造函数中m_data数据，将其copy
myString::myString(const myString &str) {
    std::cout << "copy constructor" <<std::endl;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

// 析构函数
myString::~myString() {
    std::cout << "free constructor" <<std::endl;
    if (NULL != m_data) {
        delete []m_data;
        m_data = NULL;
    }
}

// 赋值函数
myString &myString::operator=(const myString &str) {
    std::cout << "operator=" <<std::endl;
    if (this != &str) {
        m_data = new char[strlen(str.m_data) + 1];
        strcpy(m_data, str.m_data);
    }

    return *this;
}

void myString::showstr() {
    std::cout << "str = " << m_data <<std::endl;
}

int main()
{
    myString str("hyw");
    str.showstr();

    myString str1 = str;
    str1.showstr();

    return 0;
}
