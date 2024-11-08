#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h>
int main() {
  int ret, s,cnt=1;
  while(1){
	ret=fork();
	if(ret==-1){
	printf("Process creation failed\n");
	_exit(1);
	}
	else if(ret==0){
		sleep(5);
		_exit(0);
	}
	else
	{
		printf("Child count: %d",cnt);
		cnt++;

	}
}
	while(waitpid(-1,&s,0)>0){
		printf("Child exit status:%d", WEXITSTATUS(s));
	}

	return 0;
}



