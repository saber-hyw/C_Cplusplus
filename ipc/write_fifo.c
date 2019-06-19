#include<stdio.h>
#include<stdlib.h>    // exit
#include<fcntl.h>     // O_WRONLY
#include<sys/stat.h>  // FIFO API
#include<time.h>      // time
#include<errno.h>

#include <unistd.h>

#define FIFO "/tmp/fifo.3"

int main() 
{
    int fd;     // 定义FIFO文件句柄
    int n,i;
    char buf[1024];
    time_t tp;

    // 表明当前的进程ID
    printf("I am %d process.\n", getpid());

    // 先创建FIFO
    if(mkfifo(FIFO, 0777) < 0 && errno!=EEXIST) {
        perror("Create FIFO Failed");
    }
    // 再使用open函数打开FIFO
    if ((fd = open(FIFO, O_WRONLY)) < 0) { // 以读打开FIFO
        perror("Open FIFO Failed");
        exit(1);
    }
    // 循环写入当前系统时间
    for(i = 0; i < 10; ++i) {
        time(&tp);  // 取系统当前时间
        n = sprintf(buf, "Process %d's time is %s", getpid(), ctime(&tp));
        printf("Send message: %s", buf); // 打印
        if(write(fd, buf, n+1) < 0) { // 写入到FIFO中
            perror("Write FIFO Failed");
            close(fd);
            exit(1);
        }
        // 每次休眠一秒
        sleep(1);
    }

    close(fd);  // 关闭FIFO文件

    return 0; 
}