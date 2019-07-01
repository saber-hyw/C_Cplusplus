/*
 * By YongwuHan
 * 
 * 程序的思路:
 * (1)首先定义一个int类型的数组fd[2],之后作为参数传入pipe(),pipe返回值为0成功,返回值为-1失败
 * (2)得到f[0]:读端, f[1]:写端; 使用read(fd, buff, size) write(fd, buff, size)函数来传递数据
 * (3)父进程向子进程传递数据: 父进程使用写端f[1]写入数据, 子进程使用读端f[0]获取数据; 单向数据传递
 * 
 */

#include <stdio.h>
#include <unistd.h> // 包含 pipe api的头文件

int main() 
{
    int fd[2];
    char buff[20] = "No message!";

    int pipeRes = pipe(fd);
    if (pipeRes < 0) {
        printf("pipe error!");
    }

    // fork 一个进程;  pid_t 本质还是个int类型
    pid_t fpid;
    fpid = fork();
    if (fpid < 0) {
        printf("fork Error! \n");
    } else if (fpid == 0) {
        printf("this is a son pid \n");
        // 子进程通过 pipe 读取数据
        read(fd[0], buff, sizeof(buff));
        printf("buff = %s \n", buff);
    } else {
        printf("this is a father pid \n");
        // write msg, 父进程通过pipe向子进程传递数据
        write(fd[1], "I am your father", sizeof(buff));
    }

    return 0;
}
