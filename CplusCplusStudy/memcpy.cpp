/**
 * By Yongwu Han
 * 
 * memcpy 的代码思路：
 * (1) 返回值是 void* 类型的指针，void*类型方便转换成其他类型的指针；
 * (2) 参数: void *des, void *src, size_t count;
 */

#include <iostream>
#include <assert.h>

#include <string.h>

// 不考虑空间重叠版本
void *memcpy(void *des, const void *src, size_t count) {  // 不能对指针指向的内容进行修改
    assert(des != NULL && src != NULL);

    // 为了适应拷贝其他类型的连续数据(内存)，将void* 类型转为char*类型
    char *ptr_des = (char*)des;
    const char *ptr_src = (const char*)src;

    // 一样需要一个temp指针
    void *ret = des;
    while (count--)
    {
        *ptr_des++ = *ptr_src++;
    }
    
    return ret;
}



int main()
{

    char ch[4] = "hyw";
    char *desStr = new char;
    memcpy(desStr, ch, strlen(ch));
    std::cout << "str = " << desStr <<std::endl;

    return 0;
}

/**
 * 
 * https://blog.csdn.net/sszgg2006/article/details/7989404
 * 
 */