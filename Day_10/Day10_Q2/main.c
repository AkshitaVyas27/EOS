#include<stdio.h>
#include<stdlib.h>
#include"circle.h"
#include"square.h"
#include"rectangle.h"
int main(){
	while(1){
	printf("\nEnter your choice:\n0. Exit\n1. Area of circle\n2.Area of square\n3Area of rectangle\n");
	int choice;
	scanf("%d",&choice);
	if(choice==0)
	exit(0);
	switch(choice){	
	case 1:
		circle();
		break;
	case 2:
		square();
		break;
	case 3:
		rectangle();
		break;

	}
	}
	return 0;
	}
