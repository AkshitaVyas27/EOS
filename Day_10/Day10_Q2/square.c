#include<stdio.h>
#include"square.h"
int square(){
	printf("To get area of a square\n");
	
	printf("Enter the side\n");
	float s;
	scanf("%f",&s);
	printf("Area of square:%f",s*s);
	return 0;
	}
