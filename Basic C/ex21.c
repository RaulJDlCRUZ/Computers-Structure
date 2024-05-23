#include <stdio.h>

// Size of differnt basic data types

int main(){
	char c=0, *pc=&c, *pc2=pc+1;
	int i=0,*pi=&i,*pi2=pi+1;
	float f=0,*pf=&f;
	double d=0,*pd=&d;
	printf("Address of c: %p and address pointed by pc+1: %p, What is the char size? %d byte\n",pc,pc+1,sizeof(char));
	printf("Address of i: %p and address pointed by pi+1: %p, What is the int size? %d bytes\n",pi,pi+1,sizeof(int));
	printf("Address of f: %p and address pointed by pf+1: %p, What is the float size? %d bytes\n",pf,pf+1,sizeof(float));
	printf("Address of d: %p and address pointed by pd+1: %p, What is the double size? %d bytes\n",pd,pd+1,sizeof(double));
}