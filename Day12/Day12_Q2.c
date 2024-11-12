#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>


int main(){
	int arr1[2],arr2[2];
	int buff1[2],buff2[2];
	int pid;
	int ret=pipe(arr1);
	if(ret<0){
	perror("pipe1 failed\n");
	}

	int ret1=pipe(arr2);
	if(ret1<0){
	perror("pipe 2 failed\n");
	}
	pid=fork();

	if(pid==0){
	printf("enter the numbers\n");
	scanf("%d%d", &buff1[0],&buff1[1]);
	int ret1=write(arr1[1], buff1, sizeof(buff1));
	if(ret1<0){
	perror("child write failed\n");
	_exit(1);
		}
	printf("numbres sent sucessfully\n");


	printf("waiting for numbers\n");
		close(arr1[1]);
	 int ret2=read(arr2[0], buff1, sizeof(buff1));
		if(ret2<0){
		perror("parent read failed\n");
		_exit(1);
 		 }
		 printf("final result: %d", buff1[0]);
	close(arr1[0]);
	
	}
	else{
	printf("waiting for numbers\n");
	close(arr1[1]);
	 int ret2=read(arr1[0], buff2, sizeof(buff2));
		if(ret2<0){
		perror("parent read failed\n");
		_exit(1);
 		 }
		 close(arr1[0]);
	printf("recieved numbers:%d  %d", buff2[0],buff2[1]);

	buff2[0]=buff2[1]+buff2[0];
	buff2[1]=0;
	close(arr2[0]);
	int ret3=write(arr2[1], buff2, sizeof(buff2));
	if(ret3<0){
	perror("parent write failed\n");
	_exit(1);
		}
		close(arr2[1]);
	printf("numbrer sent sucessfully\n");
	}


	return 0;
}
