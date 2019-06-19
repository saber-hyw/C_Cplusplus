#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
 

int main() 
{
    int     qid;
    key_t   key;
   
    key = 113;
    qid = msgget( key, IPC_CREAT | 0666 );       /*创建一个消息队列*/
    if ( qid < 0 ) {                            /* 创建一个消息队列失败 */
        perror ( "msgget" );
        exit (1) ;
    }
   
    printf ("created queue id : %d /n", qid );  /* 输出消息队列的ID */
   
    system( "ipcs -q" );                        /*查看系统IPC的状态*/

    return 0;
}

