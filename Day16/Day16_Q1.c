#include<stdio.h>
#include<unistd.h>
#include <pthread.h>

int arr[10];
	int i,j,temp;
void* selection_sort(void *param){
	int *ptr=(int *)param;
	for(i=0;i<9;i++){
		for(j=0;j<=9;j++){
		if(ptr[i]<ptr[j]){
			temp=ptr[i];
			ptr[i]=ptr[j];
			ptr[j]=temp;
		}

		}

	}
	return NULL;
}

int main(){
	int ret,i;
	 for(i=0;i<10;i++){
		printf("Enter arr[%d]\n", i);
		scanf("%d", &arr[i]);
	 }
	pthread_t th;
 	ret=pthread_create(&th, NULL, selection_sort, &arr);
	if(ret!=0){
	printf("pthread_create() has failed");
	_exit(1);
	}

	pthread_join(th, NULL);
	for(int i=0;i<10;i++){
		printf("  arr[%d}=%d", i, arr[i]);

	}
	return 0;
	
}
