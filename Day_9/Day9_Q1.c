#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){

	int pid1,pid2,pid3,s,i;
	pid1=fork();
	if(pid1==0){
	for(i=1;i<=5;i++){
		printf("child 1: count : %d\n", i);
		sleep(1);

	}
	_exit(0);
	}
	pid2=fork();
	if(pid2==0){
	for(i=1;i<=5;i++){
		printf("child 2: count : %d\n", i);
		sleep(1);

	}
	_exit(0);
	}

	pid3=fork();
	if(pid3==0){
	for(i=1;i<=5;i++){
		printf("child 3: count : %d\n", i);
		sleep(1);

	}
	_exit(0);
	}
	for(i=1;i<=5;i++){
	printf("parent : %d\n", i);
	sleep(1);
	}

	while(waitpid(-1,&s,0)>0){
		printf("Child status : %d\n", WEXITSTATUS(s));
		}


	return 0;
}




