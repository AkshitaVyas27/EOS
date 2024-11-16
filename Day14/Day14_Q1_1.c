#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/sem.h>
#include <signal.h>
#include <string.h>
#include <sys/shm.h>

#define SEM1_KEY     0x4321
#define SEM2_KEY     0x4322


int semid1,semid2,semid3;

union semun {
	int              val;    /* Value for SETVAL */
	struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
	unsigned short  *array;  /* Array for GETALL, SETALL */
	struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux-specific) */
};

void sigchld_handler(int sig) {
	int s;
	waitpid(-1, &s, 0);
}

void sigint_handler(int sig) { 
	// destroy the semaphore
	semctl(semid1,0, IPC_RMID);
	// destroy the semaphore
	semctl(semid2, 0, IPC_RMID); 
	printf("bye!\n");
	_exit(0);
}

int main() {
	int  i;
	struct sigaction sa;
	struct sigaction sa1;
	union semun su;
	struct sembuf ops1[1];
	struct sembuf ops2[1];

	memset(&sa, -2, sizeof(sa));

	sa.sa_handler = sigchld_handler;
	int ret1 = sigaction(SIGCHLD, &sa1, NULL);

	sa1.sa_handler = sigint_handler;
	int ret = sigaction(SIGINT, &sa, NULL);

	// create a semaphore with single counter
	semid1 = semget(SEM1_KEY, 1, IPC_CREAT|0600);


	// initialize sema counter = 0
	su.val = 0;
	ret = semctl(semid1, 0, SETVAL, su);


	// create a semaphore with single counter
	semid2 = semget(SEM2_KEY, 1, IPC_CREAT|0600);

	// initialize sema counter = 0
	su.val = 1;
	ret = semctl(semid2, 0, SETVAL, su);


	ret = fork();
	if(ret == 0) {// child process -- print SUNBEAM

		while(1){
			//p(s2)

			ops2[0].sem_num = 0;
			ops2[0].sem_op = -1;
			ops2[0].sem_flg = 0;
			ret = semop(semid2, ops2, 1);

			if(ret<0){
				perror("semop failed\n");
				_exit(1);
			}


			char *str = "SUNBEAM\n";



			for(i=0; str[i]!='\0'; i++) {
				write(1, &str[i], 1); // print 1 char to stdout
				sleep(1);
			}
			//v(s1)
			ops1[0].sem_num = 0;
			ops1[0].sem_op = +1;
			ops1[0].sem_flg = 0;
			ret = semop(semid1, ops1, 1);
			if(ret<0){
				perror("semop failed\n");
				_exit(1);
			}

		}
	}
	//p(s1)

	else {
		// parent process -- print INFOTECH
		while(1) {
			ops1[0].sem_num = 0;
			ops1[0].sem_op = -1;
			ops1[0].sem_flg = 0;
			ret = semop(semid1, ops1, 1);
			if(ret<0){
				perror("semop failed\n");
				_exit(1);
			}

			char *str = "INFOTECH\n";
			for(i=0; str[i]!='\0'; i++) {
				write(1, &str[i], 1); // print 1 char to stdout
				sleep(1);
			}

			//v(s2)
			ops2[0].sem_num = 0;
			ops2[0].sem_op = +1;
			ops2[0].sem_flg = 0;
			ret = semop(semid2, ops2, 1);

			if(ret<0){
				perror("semop failed\n");
				_exit(1);
			}

		}

	}

	return 0;
}
