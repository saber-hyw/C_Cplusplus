#include <stdio.h>
#include <unistd.h> // include fork() function

int main()
{
    int count = 0;
    pid_t fpid_1, fpid_2;
    fpid_1 = fork();
    fpid_2 = fork();
    printf("count = %d \n", count);
    printf("This is printf! current pid = %d \n", getpid());

    return 0;
}