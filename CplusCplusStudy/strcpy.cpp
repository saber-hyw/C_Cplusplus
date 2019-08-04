/**
 * By Yongwu Han
 * 
 * strcpy 的代码思路：
 * （1）函数体，函数返回值是一个char *;
 * （2）传入的参数是 目标字符指针 + 被copy的字符串指针;
 * （3）assert处理
 */

#include <iostream>
#include <stdio.h>

#include <assert.h>
/**
 * void assert( int expression );
 * assert的作用是现计算表达式 expression ，如果其值为假（即为0, assert(0)终止程序），那么它先向stderr打印一条出错信息，然后通过调用 abort 来终止程序运行
 */ 

// 返回的是一个char* 类型的指针
char *strcpy(char *desStr, const char *srcStr) {   // 传入的值是const指针，最好不要修改src原始指针的值；
    // 异常处理, 最好用assrt(),会向程序发送错误消息
    // (des != NULL) 为true  && (src != NULL) 为true; 因此assert(1)，程序正常运行
    assert((desStr != NULL) && (srcStr != NULL)); 
    
    // 赋值处理
    char *ret = desStr;    // 保存字符串首地址
    while ((*(desStr++) = *(srcStr++)) != '\0');   // strcpy会拷贝 '\0'
    // {
        // *desStr = *srcStr;    // 
        // srcStr++;             // 指针可以自增自减
        // desStr++;
        // *(desStr++) = *(srcStr++);
        // 以上三段代码相当于 *(ret++) = *(src++), 先执行 *ret = *src的赋值操作, 再各自指针ret++ src++
    // }
    printf("descopy = %s\n", ret);
    return ret;         // 返回字符串的首地址
}

int main()
{

    // char ch[10] = {'h','y','w'};
    char ch[11] = "hywadsfadf";
    char *desStr = new char;
    strcpy(desStr, ch);
    std::cout << "str = " << desStr <<std::endl;

    return 0;
}
