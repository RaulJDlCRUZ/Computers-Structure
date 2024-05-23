#include <stdio.h>

// Adding the elements of an array

int main(){
    int i, sum = 0, n=4;
    int array[4]={1,2,3,4};
    for( i=0; i<n; i++) sum = sum + array[i];
    printf("The sum of the elements of the array is equal to %d\n",sum);
}