#include<stdio.h>
#include"circle.h"
int circle(){
	int r;
	printf("To get area of a circle\n");
	printf("Enter the radius\n");
	scanf("%d",&r);
	printf("Area of circle:%f",3.14*r*r);
	return 0;
	}
