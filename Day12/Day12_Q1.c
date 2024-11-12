#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include <sys/msg.h>
#define MQ_KEY 0x1234
typedef struct msg{
	long id;
	int arr[2];
	}msg_t;

int main(){
	int pid, m;
	int mqid=msgget(MQ_KEY, IPC_CREAT|0644);
	if(mqid<0){
	perror("msgget failed\n");
	_exit(1);
	}

	pid=fork();
	if(pid==0){
	msg_t t1,t4;
	int n1,n2;
	t1.id=101;
	printf("Enter two numbers\n");
	scanf("%d", &n1);
	printf("enter the second number\n");
	scanf("%d",&n2);
	t1.arr[0]=n1;
	t1.arr[1]=n2;
	printf("hello\n");
		int ret=msgsnd(mqid, &t1, sizeof(msg_t)-sizeof(long), 0);
		if(ret==-1){
		perror("msgsnd failed");
		_exit(1);
		}
	printf("first message sent\n");

	printf("child waiting for message\n");
	int ret3=msgrcv(mqid, &t4, sizeof(msg_t)-sizeof(long), 202, 0);
	if(ret3<0){
	perror("msgrcv has failed\n");
	_exit(1);

	}
	printf("child message recieved\n");
	printf("final result:%d\n", t4.arr[0]);

	}

	else{
	msg_t t2,t3;
	printf("waiting for message\n");
	int ret2=msgrcv(mqid, &t2, sizeof(msg_t)-sizeof(long), 101, 0);
	if(ret2<0){
	perror("msgrcv has failed\n");
	_exit(1);

	}
	printf("first message recieved\n");
	
	
	printf("parent sending added nnumbers");

	t3.id=202;
	t3.arr[0]=t2.arr[0]+t2.arr[1];
	t3.arr[1]=0;
	int ret1=msgsnd(mqid, &t3, sizeof(msg_t)-sizeof(long), 0);
		if(ret1==-1){
		perror("msgsnd failed");
		_exit(1);
		}
	printf("parent message sent\n");




	}


	return 0;
	}
