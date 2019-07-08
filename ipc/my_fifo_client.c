/**
 * By Yongwu Han
 * 
 * fifo:命名管道
 * 实现的功能: 不相干的两个进程之间，使用FIFO通信
 * 程序思路:
 * (1) 首先使用API mkfifo() 创建FIFO文件
 * (2) 对FIFO文件进行错误检查
 * (3) 使用open(fifo, Read|write)
 * (4) 最后进行读写数据
 * 
 */


#include <stdio.h>
#include <errno.h>
#include <sys/types.h>  // error type
#include <sys/stat.h>   // FIFO API
#include <unistd.h>
#include <fcntl.h>      // O_WRONLY
#include <string.h>
#include <stdlib.h>
 
#define MAXLINE 1024
#define FIFO1 "/tmp/fifo.1"
#define FIFO2 "/tmp/fifo.2"
 
void Perror(const char *s)
{
    perror(s);
    exit(EXIT_FAILURE);
}

// write msg to fifo
void client(int readfd, int writefd)
{
    /* read msg  */
    for (int i = 0; i<3; i++) {
        char buff[MAXLINE] = {0};
        int n = read(readfd, buff, MAXLINE);
        if (n > 0) {
            printf("read from server:%s\n", buff);
        } else {
            printf("read error!\n");
        }
    }
    const char *buff = "goodby server";
    write(writefd, buff, strlen(buff));
}
 
int main()
{
    int readfd, writefd;
    int res_mkfifo_1, res_mkfifo_2;

    // 创建 FIFO
    res_mkfifo_1 = mkfifo(FIFO1, 0666);
    res_mkfifo_2 = mkfifo(FIFO2, 0666);
 
    // error 判断
    if ((res_mkfifo_1 < 0) && (errno != EEXIST)) {
        Perror("can't create FIFO1");
    }
    if ((res_mkfifo_2 < 0) && (errno != EEXIST)) {
        unlink(FIFO1); /* rm FIFO1 */
        Perror("can't create FIFO2");
    }
 
    /* 要注意open的顺序, 和server的读写恰好相反 */
    writefd = open(FIFO2, O_WRONLY);  // 写
    readfd = open(FIFO1, O_RDONLY);   // 读
 
    client(readfd, writefd);
 
    return 0;
}
