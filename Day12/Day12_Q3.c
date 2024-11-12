#include<stdio.h>
#include <unistd.h>


int main(){

	int arr[2];
	char buff[1]="A";
	int count=0;
	int ret=pipe(arr);
	if(ret<0){
	printf("pipe has failed");
	_exit(1);
	}

	while(1){
	write(arr[1], buff, sizeof(buff));
	count++;
	printf("count: %d\n", count);
	}

	return 0;
}
