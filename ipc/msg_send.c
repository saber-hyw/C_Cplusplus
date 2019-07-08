
/**
 * By Yongwu Han
 * 
 * 程序实现的功能: 向消息队列里发送消息
 * 程序思路:
 * (1) 首先，定义消息结构
 * (2) 使用msgget() API 建立消息队列
 * (3) 使用msgsnd() API 向消息队列里面发送消息
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
 
#define MAX_TEXT 512

// 消息的数据结构
struct msg_st
{
	long int msg_type;
	char text[MAX_TEXT];  // MAX_TEXT 即 msg_sz: 是不包括长整型消息类型成员变量的长度。
};

int main()
{
	int running = 1;
	struct msg_st data;
	char buffer[BUFSIZ];
	int msgid = -1;

	 
	//建立消息队列
	msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
	if(msgid == -1)
	{
		fprintf(stderr, "msgget failed with error: %d\n", errno);
		exit(EXIT_FAILURE);
	}

	//向消息队列中写消息，直到写入end
	while(running)
	{
		//输入数据
		printf("Enter some text: ");
		fgets(buffer, BUFSIZ, stdin);
		data.msg_type = 1;    //注意2
		strcpy(data.text, buffer);
		//向队列发送数据
		if(msgsnd(msgid, (void*)&data, MAX_TEXT, 0) == -1)
		{
			fprintf(stderr, "msgsnd failed\n");
			exit(EXIT_FAILURE);
		}
		//输入end结束输入
		if(strncmp(buffer, "end", 3) == 0)
			running = 0;
		sleep(1);
	}
	exit(EXIT_SUCCESS);

	return 0;
}



