#include <stdio.h>
int main() {
    int x =10;
    int *p; //pointer declaration
    p = &x; //assigning address of x to p
    // printf("value of x: %d\n",x);
    // printf("address of x: %p\n",&x);
    printf("value of x using pointer: %d\n", *p);
    // printf("value of x using pointer: %d\n", *p);
    printf("address of x using pointer: %p\n", p);
    return 0;




}