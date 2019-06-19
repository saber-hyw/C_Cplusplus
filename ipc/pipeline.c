#include <stdio.h>
#include <unistd.h>  // 管道的include文件

/*
以下程序显示的是：
数据流从父进程流向子进程，关闭父进程的读端（fd[0]）与子进程的写端（fd[1]）
*/

int main() 
{
    int fd[2];  // 两个文件描述符
    pid_t pid;  // pid_t 本质是就是int类型

    char buff[20];  // 定义一组测试数据
    
    if(pipe(fd) < 0) {
        printf("Create pipe Error\n");
    }
    // 创建子线程pid = fork()
    if((pid = fork()) < 0) {
        printf("Fork Error!\n");
    } else if (pid > 0) { // 父进程  
        close(fd[0]);     // 关闭父进程的读端
        // 
        write(fd[1], "hello,world", 12); //+结束符 \0
    } else {
        close(fd[1]);   // 关闭写端
        read(fd[0], buff, 20);
        printf("read data from PPID = %s\n", buff);
    }

    return 0;
}




