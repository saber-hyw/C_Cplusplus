/**
 * By Yongwu Han
 * 
 * 程序思路:
 * (1)定义一个结构体，用于创建共享内存
 * 定义一个void类型的指针，用于接收共享内存中结构体数据的地址
 * (2)使用shmget()函数创建共享内存
 * (3)使用shmat()函数将共享内存和当前进程的空间地址连接起来
 * (4)读写数据
 * (5)使用shmdt()函数断开和共享内存的链接
 * (6)删除共享内存, 在共享内存不用的时候一定要删除, 不然会造成不可预测的错误
 */


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/shm.h>
#include "shmdata.h"

int main()
{
    int running = 1;
    void *shm = NULL;  // 分配共享内存的原始首地址；
    // 定义一个结构体指针, 指向shm
    ShmUseSt *pShared; 
    int shmid;  // 共享内存的标识符

    // 创建共享内存;(创建ShmUseSt 结构体大小的共享内存, 用于数据交换)
    shmid = shmget((key_t)1234, sizeof(ShmUseSt), 0666|IPC_CREAT);
    if (-1 == shmid) {
        printf("shmget Error!\n");
        exit(EXIT_FAILURE);
    }

    // 将共享内存连接到当前进程的地址空间
    shm = shmat(shmid, 0 , 0);
    // 比较地址
    if (shm == (void*)-1) {
        printf("shmat Error!\n");
        exit(EXIT_FAILURE);
    }
    printf("Memory attached at %x\n", (unsigned int *)shm);

    // 连接共享内存的数据, 将获取的shm共享空间的地址(即共享内存中存储结构体的地址)
    pShared = (ShmUseSt*)shm;
    // 置标志位written = 0, 写数据
    pShared->written = 0;
    while (running) {
        // if written != 0, 表示其他的进程没有在写数据
        // 去读取其他进程写入的数据
        if (pShared->written !=0 ) {
            printf("other process wrote: %s", pShared->text);
            sleep(rand() % 3);
            //读取完数据，设置written使共享内存段可写
			pShared->written = 0;
			//输入了end，退出循环（程序）
			if(strncmp(pShared->text, "end", 3) == 0)
				running = 0;
        } else {
            // 有进程在写数据, 等待
            printf("Other processes writing data\n");
            sleep(1);
        }
    }
    
    // 断开共享内存的连接
    if(-1 == shmdt(shm)) {
        printf("shmdt failed \n");
        exit(EXIT_FAILURE);
    }

    // 删除共享内存
    if(-1 == shmctl(shmid, IPC_RMID, 0)) {
        printf("shmctl(IPC_RMID) failed \n");
        exit(EXIT_FAILURE);
    }

    return 0;
}