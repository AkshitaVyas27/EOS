#include<stdio.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>

void SIG_handler(int sig){
	int s;
	waitpid(-1,&s,0);
	printf("child exit status: %d\n", WEXITSTATUS(s));

}

int main(){
	int pid,s,i,pid1;
	char cmd[512];
	char *ptr;
	char *args[512];
	struct sigaction sa;
	memset(&sa,0, sizeof(struct sigaction));
	sa.sa_handler=SIG_handler;
	int ret=sigaction(SIGCHLD, &sa,NULL);
	if (ret<0){
		printf("SIGACTION failed");
		_exit(1);
	}
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

		//for(int i=0; args[i]!=NULL; i++)
		//	printf("args %d = %s\n", i, args[i]);
		//printf("args[i-2] = %s\n", args[i-2]);

		if(strcmp(args[0],"cd")==0){
			chdir(args[1]);
		}

		else if(strcmp(args[0],"exit")==0){
			_exit(0);
		}

		else if(strcmp(args[i-2],"&")==0){
			printf("async execution\n");
			args[i-2]=NULL;
			pid1=fork();
			if(pid1==0){
				int err=execvp(args[0],args);
				if(err<0){
					printf("execv() has failed\n");
					_exit(1);
				}
			}
			else{
				printf("Parent not waiting\n");
			}
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
				printf("Parent waiting\n");
				pause();
			}
		}
	}
	return 0;
}
