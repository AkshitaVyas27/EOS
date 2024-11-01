#include<stdio.h>
 #include <sys/types.h>
 #include <dirent.h>
 #include<stdlib.h>


int main(int argc, char *argv[]){
DIR *d;
 d=opendir(argv[1]);
 if(d==NULL){
 printf("\nError while opening the file");
 exit(1);
}

else
{
	printf("\nFile opened successfully");
}

 

struct dirent *dp;
while((dp=readdir(d))!=NULL)
 {
 printf("\nFile name:%s", dp->d_name);
 printf("\nInode number:%lu", dp->d_ino);
 printf("\nFile size:%d", dp->d_reclen);
}
 int ret1= closedir(d);
 if(ret1=-1){
 printf("\nError in closing the file\n");
 }
 else{
 printf("\nFile closed successfully");
 }

 return 0;
 }
