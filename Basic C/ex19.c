#include <stdio.h>

// Use of floating point

int main(){
    double sum;
    int i, n=5;
    float avg, y[5]={1.1,3.5,2.2,6.7,8.0};
    sum = 0.0;
    for( i=0; i<n; i++ ){
        sum += y[i];
    }
    avg = sum/n;
    printf("The average value of the elments in vector y is: %f\n", avg);
    printf("The sum value of the elments in vector y is: %f\n", sum);
}