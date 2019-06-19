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
 
void client(int readfd, int writefd)
{
    /* read msg  */
    for (int i = 0; i<3; i++) {
        char buff[MAXLINE] = {0};
        int n = read(readfd, buff, MAXLINE);
        if (n > 0) {
            printf("read from server:%s\n", buff);
        }
    }
    const char *buff = "goodby server";
    write(writefd, buff, strlen(buff));
}
 
int main()
{
    int readfd, writefd;
 
    /* create two FIFO; OK if they already exist */
    if ((mkfifo(FIFO1, 0777) < 0) && (errno != EEXIST))
        Perror("can't create FIFO1");
    if ((mkfifo(FIFO2, 0777) < 0) && (errno != EEXIST)) {
        unlink(FIFO1); /* rm FIFO1 */
        Perror("can't create FIFO2");
    }
 
    /* 要注意open的顺序, 和server的读写恰好相反 */
    writefd = open(FIFO2, O_WRONLY);
    readfd = open(FIFO1, O_RDONLY);
 
    client(readfd, writefd);
 
    return 0;
}
