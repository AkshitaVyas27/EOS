#include<stdio.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>
 #include <signal.h>

void Int_Handler(int sig){

	printf("Terminating process\n");
	}


int main(){
struct sigaction sa,sold;
sa.sa_handler=Int_Handler;

	int err=sigaction(SIGINT, &sa, &sold);
	if(err==-1){
	printf("SIGACTION FAILED\n");
	}
	int pid,s,i;
	char cmd[512];
	char *ptr;
char *args[512];
while(1){
	printf("\ncmd>");
	gets(cmd);
	ptr=strtok(cmd, " ");
	i=0;

	args[i++]=ptr;

	do{
	ptr=strtok(NULL, " ");
	args[i++]=ptr;
	}while(ptr!=NULL);
	
	if((strcmp(args[0],"cd"))==0){
	chdir(args[1]);
	}
	
	else if((strcmp(args[0],"exit"))==0){
		_exit(0);
	}
	
else {
	pid=fork();
	if(pid==0){
	int err=execvp(args[0],args);
	if(err<0){
	printf("execv() has failed\n");
	_exit(1);
	}
	}
	else{
	waitpid(-1, &s,0);

	}
  }
}
	return 0;
	}
