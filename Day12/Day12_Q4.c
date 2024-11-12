#include<stdio.h>
#include<unistd.h>

int main(){
	int arr[2];
	int s;
	int ret=pipe(arr);
	if(ret<0){
	printf("error in pipe\n");
	_exit(1);
	}
	int pid1=fork();
	if(pid1==0){
	close(arr[0]);
	dup2(arr[1], 1);
	close(arr[1]);
	int err1=execlp("who","who",NULL);
	if(err1<0){
	perror("err1 failed\n");
	_exit(1);
	}
	}

	int pid2=fork();
	if(pid2==0){

	close(arr[1]);
	dup2(arr[0], 0);
	close(arr[0]);
	int err2=execlp("wc","wc",NULL);
	if(err2<0){
	perror("err1 failed\n");
	_exit(1);
	
	}
	int err3=execlp("wc","wc",NULL);
	if(err3<0){
	perror("err2 failed\n");
	_exit(1);
	}
	}
	close(arr[1]);
	close(arr[0]);
	waitpid(-1, &s, 0);

	



	return 0;
}
