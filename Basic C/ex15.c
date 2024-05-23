#include <stdio.h>

// A function to swap values of two variables only works if we pass values by reference using pointers

void swap_val(int x, int y){
	int temp;
	temp=x;
	x=y;
	y=temp;
}

void swap_ref(int *px, int *py){
	int temp;
	temp=*px;
	*px=*py;
	*py=temp;
}

int main(){
	int x=1, y=2;
	swap_val(x,y);
	printf("If we pass arguments by value now x is %d and y is %d\n",x,y);
	swap_ref(&x,&y);
	printf("If we pass arguments by reference now x is %d and y is %d\n",x,y);
}