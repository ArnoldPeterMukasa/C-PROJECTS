#include <stdio.h>
#define max 100 //maximum size of the stack
int stack[max]; //array to store stack elements 
int top = -1; //top pointer initialized to -1, indicating an empty stack
//function to  push an element onto the stack
void push(int value) {
    if (top == max - 1) {
        printf("stack overflow! cannot push %d\n", value);
        return;
    } 
    stack[++top]=value; //increment top and insert a value
}
//function to pop an element from the stack
int pop() {
    if(top == -1) {
        printf("stack underflow! cannot pop\n");
        return -1; //returns -1 indicating an error
    }
    return stack[top--]; //return top value and decrement top
}
//function to display the stack
void display() {
    if(top == -1) {
        printf("stack is empty\n");
        return;
    }
    printf("stack (top to bottom):\n");
    for(int i= top; i>0; i--) {
        printf("%d\n", stack[i]);
    }
}
int main() {
    //initial stack: {4,3,5,6,7,8,9} (9 is the top)
    push(4);
    push(3);
    push(5);
    push(6);
    push(7);
    push(8);
    push(9);

    printf("initial stack:\n");
    display();

    //given operations
    push(4);
    pop();
    pop();
    pop();
    push(7);

    printf("\nfinal stack after the operations:\n");
    display();
    return 0;

}