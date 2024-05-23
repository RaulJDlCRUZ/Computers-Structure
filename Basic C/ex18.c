#include <stdio.h>

// Use of structures

struct User
{
    char *name;
    int age;
    char gender;
    float height;
    float weight;
};


int main(){
    struct User members[10];

    members[0].name="John";
    members[0].age=20;
    members[0].gender='M';
    members[0].height=1.78;
    members[0].weight=72.6;

    members[1].name="Sally";
    members[1].age=25;
    members[1].gender='F';
    members[1].height=1.65;
    members[1].weight=60.3;
    
    printf("The name, age, gender, height and weight of user 0 is: %s, %d, %c, %f, %f\n", members[0].name,members[0].age,members[0].gender,members[0].height,members[0].weight);
    printf("The name, age, gender, height and weight of user 1 is: %s, %d, %c, %f, %f\n", members[1].name,members[1].age,members[1].gender,members[1].height,members[1].weight);
}