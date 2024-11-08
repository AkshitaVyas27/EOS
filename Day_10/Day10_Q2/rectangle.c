#include<stdio.h>
#include"rectangle.h"
int rectangle(){
	float l,b;
	printf("To get area of a rectangle\n");
	
	printf("Enter the length\n");
	scanf("%f",&l);
	printf("Enter the breadth\n");
	scanf("%f",&b);
	printf("Area of rectangle:%f",l*b);
	return 0;
	}
