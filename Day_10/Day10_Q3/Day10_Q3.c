#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	int pid1,pid2,pid3,pid4,pid5,pid6,s1,s2,s3,s4,s5,s6,err1,err2,err3,err4,err5,err6;
	pid1=fork();
	if(pid1==0){ 
        char *args[] = {"gcc", "-c", "circle.c", NULL};
        err1 = execv("/usr/bin/gcc", args);
        if(err1 < 0) {
            perror("exec() failed");
            _exit(1);
        }
		_exit(0);

	}

	pid2=fork();
      if(pid2==0){  
         char *args[] = {"gcc", "-c", "square.c", NULL};
         err2 = execv("/usr/bin/gcc", args);
         if(err2 < 0) {
              perror("exec() failed");
            _exit(1);
         }
 	_exit(0);
 
     }

	 pid3=fork();
      if(pid3==0){
         char *args[] = {"gcc", "-c", "rectangle.c", NULL};
         err3 = execv("/usr/bin/gcc", args);
         if(err3 < 0) {
              perror("exec() failed");
            _exit(1);
         }
		_exit(0);

     }
	 pid4=fork();
      if(pid4==0){
         char *args[] = {"gcc", "-c", "main.c", NULL};
         err4 = execv("/usr/bin/gcc", args);
         if(err4 < 0) {
              perror("exec() failed");
            _exit(1);
         }
		_exit(0);

     }


	waitpid(pid1, &s1,0);
	printf("Child 1 exit status:%d\n", WEXITSTATUS(s1));

	waitpid(pid2, &s2,0);
	printf("Child 2 exit status:%d\n", WEXITSTATUS(s2));


	waitpid(pid3, &s3,0);
	printf("Child 3 exit status:%d\n", WEXITSTATUS(s3));


	waitpid(pid4, &s4,0);
	printf("Child 4 exit status:%d\n", WEXITSTATUS(s4));

	if((WEXITSTATUS(s1)|WEXITSTATUS(s2)|WEXITSTATUS(s3)|WEXITSTATUS(s4))==0){
	
		pid5=fork();
      if(pid5==0){  
         char *args[] = {"gcc", "-o","program.out", "circle.o","square.o","rectangle.o","main.o", NULL};
         err5 = execv("/usr/bin/gcc", args);
         if(err5 < 0) {
              perror("exec() failed");
            _exit(1);
         }
		_exit(0);
 
     }

	waitpid(pid5, &s5,0);
	printf("Child 5 exit status:%d\n", WEXITSTATUS(s5));
	if((WEXITSTATUS(s5))==0){
		
	 pid6=fork();
      if(pid6==0){
         char *args[] = {"./program.out", NULL};
         err6 = execv("./program.out", args);
         if(err6 < 0) {
              perror("exec() failed");
            _exit(1);
         }
		_exit(0);
		}
	waitpid(pid6, &s6,0);
	printf("Child 6 exit status:%d\n", WEXITSTATUS(s6));
	

	}

	else{
	printf("Child 5 status failed\n");
	_exit(1);

	}
}








else{
	printf("Child 1, 2, 3, 4 status unsuccessful\n");
	_exit(1);
}






	return 0;
}
