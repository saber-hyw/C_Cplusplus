
#include <stdio.h>
#include <stdlib.h>

// 财务统计状况函数
static int finance_result(int *a, int n);  // 不一定非要使用static函数，这里只是其他文件不可以使用这个函数；

// 老板想看财务；  参数里面有一个函数的 函数指针；
void boss_read_finance(int *array, int n, int (*fp)(int *, int));

int main(int argc, char *argv[])
{
    // 定义一个数组数据
    int array[10] = {1,2,3,4,5,6,7,8,9,10};

    boss_read_finance(array, 10, finance_result); // 这里的话传递的是函数名？ 为什么
    // => C语言中，函数名也是地址；（如果形参需要传入指针的话，直接传入函数名就可以了）

}

// 老板查看财务的实现，参数中有一个函数指针
/**
 * 传入一个 int 类型的函数指针；函数指针调起对应的函数，执行函数并返回函数结果；
 **/
void boss_read_finance(int *array, int n, int (*fp)(int *a, int n)) {
    int result = (*fp)(array, n);
    printf("老板看到的直接结果 = %d\n", result);
}

// 财务的具体实现
static int finance_result(int *a, int n) {
    int result = 0;
    int i = 0;
    for (i = 0; i < n; i++) {
        result += *(a + i);
    }
    return result;
}

/**
 * 总结： C语言的callback函数；
 * （1） 定义两个函数，其中一个函数的形参是另一个函数的函数指针；
 * 如 void funcA(int a, int b, int (*func)(int c, int c))
 * （2） C语言中，函数名也是函数指针（函数地址）；
 **/

/**
 * https://blog.csdn.net/qq_29924041/article/details/74857469
 **/