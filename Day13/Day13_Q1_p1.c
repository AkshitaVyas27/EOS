#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include <fcntl.h>

int main(){

	int fd= open("/tmp/myfifo", O_WRONLY);
	if(fd<0){
	printf("client file open fail\n");
	}
	int buff1[2],buff2[2];
	printf("Enter two numbers\n");
	buff1[0]=10;
	buff1[1]=20;
	write(fd, buff1, sizeof(buff1));
	printf("client:message sent to server\n");
	close(fd);
 	//read(int fd, void *buf, size_t count);
	int fs=open("/tmp/myfifo1", O_RDONLY);
	if(fs<0){
	printf("server file open fail\n");
	}
	read(fs, buff2, sizeof(buff2));
	printf("Client final data: %d\n", buff2[0]);
	 close(fs);



	return 0;
}
