#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
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

void server(int readfd, int writefd)
{
    /* send msg  */
    for (int i = 0; i<3; i++) {
        char buff[MAXLINE] = {0};
        sprintf(buff, "hello world %d", i);
        int n = write(writefd, buff, strlen(buff));
        sleep(1);
    }
    char buff[MAXLINE] = {0};
    int n = read(readfd, buff, MAXLINE);
    if (n > 0) {
        printf("read from client:%s\n", buff);
    }
}

int main()
{
    int readfd, writefd;
 
    /* create two FIFO; OK if they already exist */
    if ((mkfifo(FIFO1, 0777) < 0) && (errno != EEXIST))
        Perror("can't create FIFO1");
    // If can not creat fifo2, rm fifo1    
    if ((mkfifo(FIFO2, 0777) < 0) && (errno != EEXIST)) {
        unlink(FIFO1); /* rm FIFO1 */
        Perror("can't create FIFO2");
    }
    printf("create fifo success\n");
 
    /* 要注意open的顺序 */
    readfd = open(FIFO2, O_RDONLY, 0);
    writefd = open(FIFO1, O_WRONLY, 0);
    printf("open fifo success\n");
    
    /* 让FIFO在进程结束后自动删除 */
    unlink(FIFO1);
    unlink(FIFO2);
 
    server(readfd, writefd);
 
    return 0;
}