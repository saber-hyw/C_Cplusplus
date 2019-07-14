/**
 * By yongwu han
 * 
 * 程序思路:
 * 
 * 
 * 
 */


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/shm.h>
#include <string.h>
#include "shmdata.h"

int main()
{
    int running = 1;
    void *shm = NULL;  // 分配共享内存的原始首地址；
    // 定义一个结构体指针, 指向shm
    ShmUseSt *pShared; 
    int shmid;  // 共享内存的标识符
    char buffer[BUFSIZ + 1];  // 用于保存输入的文本

    // 创建共享内存;(创建ShmUseSt 结构体大小的共享内存, 用于数据交换)
    shmid = shmget((key_t)1234, sizeof(ShmUseSt), 0666|IPC_CREAT);
    if (-1 == shmid) {
        printf("shmget Error!\n");
        exit(EXIT_FAILURE);
    }

    // 将共享内存连接到当前进程的地址空间
    shm = shmat(shmid, 0 , 0);
    if (shm == (void*)-1) {
        printf("shmat Error!\n");
        exit(EXIT_FAILURE);
    }
    printf("Memory attached at %X\n", (int)shm);

    // 连接共享内存的数据, 将获取的shm共享空间的地址(即共享内存中存储结构体的地址)
    pShared = (ShmUseSt*)shm;

    while(running)//向共享内存中写数据
	{
		//数据还没有被读取，则等待数据被读取,不能向共享内存中写入文本
		while(pShared->written == 1)
		{
			sleep(1);
			printf("Waiting...\n");
		}
		//向共享内存中写入数据
		printf("Enter some text: ");
		fgets(buffer, BUFSIZ, stdin);
		strncpy(pShared->text, buffer, TEXT_SZ);
		//写完数据，设置written使共享内存段可读
		pShared->written = 1;
		//输入了end，退出循环（程序）
		if(strncmp(buffer, "end", 3) == 0)
			running = 0;
	}

    //把共享内存从当前进程中分离
	if(shmdt(shm) == -1)
	{
		fprintf(stderr, "shmdt failed\n");
		exit(EXIT_FAILURE);
	}
	sleep(2);

    return 0;
}