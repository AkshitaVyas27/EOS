#include<stdio.h>
#include <signal.h>
#include<stdlib.h>
int main(){

	printf("Enter the pid number:\n");
	int sig;
	int pid,choice;
	scanf("%d",&pid);

	printf("enter the signal number\n");
	scanf("%d",&sig);
	int ret= kill(pid, sig);
	if(ret==-1){
		printf("operation  uncessfull\n");
		return -1;
		}
	else{
	printf(" operation successfully.\n");
	    }
	
	
		return 0;
}
