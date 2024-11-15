#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include<unistd.h>

struct num{

	int num1;
	int num2;
	int sum;
};



void* add_fxn(void *param){
printf("in the function\n");
	
	struct num *n=(struct num*)param;
	n->sum=0;
	for(int i=n->num1; i<=n->num2;i++){
	n->sum=n->sum+i;
	}
	
	printf("answer : %d\n", n->sum);

}

int main(){
	pthread_t th;
	struct num n={n.num1=10, n.num2=13};
	printf("%d %d\n", n.num1, n.num2 );
   int r= pthread_create(&th, NULL, add_fxn, &n);
   printf("r: %d", r);
	if(r!=0){
	printf("failed\n");
	_exit(1);
}
printf("after the call\n");
	return 0;
}
