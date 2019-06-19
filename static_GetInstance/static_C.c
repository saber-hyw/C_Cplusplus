
/**
 * C 语言中 static的用法
 *(一) 静态全局变量:
 * (1) 在全局变量前加上 static 关键字, 即为静态全局变量;
 * (2) 默认初始化为0,直到程序结束才会销毁;
 * (3) 静态全局变量,默认时internal属性,在其他文件中不可见;
 * [普通全局变量,默认是external属性,在同一程序的其他文件可见;]
 * 
 * (二) 静态局部变量:
 * (1) 静态局部变量, 存储在数据区(不在栈区)，程序执行之前就已分配内存，程序执行结束后才销毁
 * (2) 其作用域与局部变量的作用域一样，从定义处到所处语句块结束
 * 
 * (三)静态函数:
 * (1)只能在 本文件 中使用
 * 
 **/



// #include "static_C.h"

// static 

#include <stdio.h>
#include <stdlib.h>
int k1 = 1;
int k2;
static int k3 = 2;
static int k4;
int main( )
{   static int m1=2, m2;
    int i=1;
    char*p;
    char str[10] = "hello";
    char*q = "hello";
    p= (char *)malloc( 100 );
    free(p);
    printf("栈区-变量地址  i：%p\n", &i);
    printf("                p：%p\n", &p);
    printf("              str：%p\n", str);
    printf("                q：%p\n", &q);
    printf("堆区地址-动态申请：%p\n", p);
    printf("全局外部有初值 k1：%p\n", &k1);
    printf("    外部无初值 k2：%p\n", &k2);
    printf("静态外部有初值 k3：%p\n", &k3);
    printf("    外静无初值 k4：%p\n", &k4);
    printf("  内静态有初值 m1：%p\n", &m1);
    printf("  内静态无初值 m2：%p\n", &m2);
    printf("文字常量地址    ：%p, %s\n",q, q);
    printf("程序区地址      ：%p\n",&main);
    return 0;
}
