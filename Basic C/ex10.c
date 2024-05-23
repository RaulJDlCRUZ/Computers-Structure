#include <stdio.h>

// Initializing a 2D array with two nested for loops

int main(){
    int i, j, n=4, m=4;
    int array[4][4];
    for( i=0; i<n; i++ ){
        for( j=0; j<m; j++ ){
            array[i][j]=0;
            printf("Element [%d][%d] or array is %d\n",i,j,array[i][j]);
        }
    }
}