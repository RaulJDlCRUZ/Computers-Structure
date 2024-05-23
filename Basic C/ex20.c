#include <stdio.h>

// Passing arguments by value or reference

void changeValueValue(float vpi){
	vpi=0;
	printf("Address of vpi: %p\n",&vpi);
	printf("Value of vpi: %f\n",vpi);
}

void changeValueReference(float *vpi){
	*vpi=0;
	printf("Address of vpi: %p\n",vpi);
	printf("Value of vpi: %f\n",*vpi);
}

int main(){
	float pi=3.14;
	changeValueValue(pi);
	printf("Address of pi: %p\n",&pi);
	printf("Value of pi: %f\n",pi);
	changeValueReference(&pi);
	printf("Address of pi: %p\n",&pi);
	printf("Value of pi: %f\n",pi);
}