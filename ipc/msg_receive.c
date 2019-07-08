
/**
 * By Yongwu Han
 * 
 * 程序实现的功能: 从消息队列里面获取特定的消息
 * 程序思路:
 * (1) 首先，定义消息结构
 * (2) 使用msgget() API 建立消息队列
 * (3) 使用msgrcv() API 接收特定的消息
 * (4) 使用msgctl() API 删除消息队列
 */


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

// 以下是message queue 所用到的系统头文件
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
 
// 定义消息结构
struct msg_st
{
	long int msg_type;
	// 使用 stdio.h 中的BUFSIZ(512)
	char text[BUFSIZ]; // MAX_TEXT 即 msg_sz: 是不包括长整型消息类型成员变量的长度。
};
 
int main()
{
	int running = 1;
	int msgid = -1;
	struct msg_st data;
	long int msgtype = 0; //注意1

	key_t key;
	// 建立消息队列
    key=123456;
    msgid = msgget(key, 0666 | IPC_EXCL | IPC_CREAT);
	printf("msgid = %d \n", msgid);
	if(msgid == -1)
	{
		fprintf(stderr, "msgget failed with error: %d\n", errno);
		exit(EXIT_FAILURE);
	}
	// 从队列中获取消息，直到遇到end消息为止
	while(running)
	{
		if(msgrcv(msgid, (void*)&data, BUFSIZ, msgtype, 0) == -1)
		{
			fprintf(stderr, "msgrcv failed with errno: %d\n", errno);
			exit(EXIT_FAILURE);
		}
		printf("You wrote: %s\n",data.text);
		// 遇到end结束
		if(strncmp(data.text, "end", 3) == 0)
			running = 0;
	}
	// 删除消息队列
	if(msgctl(msgid, IPC_RMID, 0) == -1)
	{
		fprintf(stderr, "msgctl(IPC_RMID) failed\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);

	return 0;
}