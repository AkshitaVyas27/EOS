#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include <fcntl.h>

int main(){
int buff1[2],buff2[2];
int fd= open("/tmp/myfifo", O_RDONLY);
printf("hello im server\n");
	if(fd<0){
	printf("server file open fail\n");
	}
	read(fd,buff1, sizeof(buff1));
	printf("Data from client on server: num1 %d   num2 %d", buff1[0], buff1[1]);
	close(fd);

	int fs=open("/tmp/myfifo", O_WRONLY);
	if(fs<0){
	printf("server file open fail\n");
	}
	
	buff2[0]=buff1[1]+buff1[0];
	buff2[1]=0;
	write(fd, buff2, sizeof(buff2));
	printf("Server data written\n");
	close(fs);


	return 0;
}
