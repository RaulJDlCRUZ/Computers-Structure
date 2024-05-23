#include <stdio.h>

// Counting different types of characters: letters, numbers and other symbols

int main( ) {
    int let, dig, other, c;
    let = dig = other = 0;
    while((c=getchar()) != '\n'){
        if(('A'<=c && c<='Z') || ('a'<=c && c<='z')) ++let;
        else if('0'<=c && c<='9') ++dig;
        else ++other;
    }
    printf("%d letters, %d digits, %d rest\n", let, dig, other);
}