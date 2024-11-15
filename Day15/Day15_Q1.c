#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include<unistd.h>

struct num{

	int num1;
	int num2;
};

struct out{
	int sum;

};



void* add_fxn(void *param){
printf("in the function\n");
	struct out *ptr=(struct out*)malloc(sizeof(struct out));	
	struct num *n=(struct num*)param;
	ptr->sum=0;
	for(int i=n->num1; i<=n->num2;i++){
	ptr->sum=ptr->sum+i;
	}
	
	printf("answer : %d\n", ptr->sum);
    return ptr;
}

int main(){
	pthread_t th;
	struct out *op;
	struct num n={n.num1=10, n.num2=13};
	printf("%d %d\n", n.num1, n.num2 );
   int r= pthread_create(&th, NULL, add_fxn, &n);
   printf("r: %d", r);
	if(r!=0){
	printf("failed\n");
	_exit(1);
}
printf("after the call\n");
	pthread_join(th, (void**)&op);
	printf("in main:%d", op->sum);
	return 0;
}
