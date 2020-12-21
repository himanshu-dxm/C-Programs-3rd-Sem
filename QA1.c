// Implement Primitive Operations on stack using Arrays.
#define MAX 30
#include<stdio.h>
#include<stdlib.h>

int stackFull(int top) {
    if(top==MAX) {
        return 1;
    }
    return 0;
}

int stackEmpty(int top) {
    if(top==-1)
        return 1;
    return 0;
}

int push(int s[],int top) {
    if(stackFull(top)) {
        printf("Stack Overflow");
        printf("Cannot Insert.");
        return top;
    }
    int value;
    printf("Enter the data to be inserted:-");
    scanf("%d",&value);
    s[++top]=value;
    printf("Data Inserted Successfully");
    return top;
}

int pop(int s[],int top) {
    if(stackEmpty(top)) {
        printf("Stack Underflow");
        printf("Cannot Delete");
        return -1;
    }
    printf("Element Popped out is");
    printf("%d",s[top--]);
    return top;
}

void peek(int s[],int top) {
    printf("\nThe values from the top elements are:-\n");
    while(top>=0) {
        printf("%d\n",s[top]);
        top--;
    }
}

void main() {
     int choice=-1;
     int top=-1;
     int stack[MAX];
     while(choice!=4) {
        printf("\nWelcome to stack implementation using arrays:-");
        printf("\nThe Operations are:-");
        printf("\n1->Insert an Element");
        printf("\n2->Delete an Element");
        printf("\n3->Display the Stack Contents");
        printf("\n4->Exit the Menu");
        printf("\nEnter your choice:-");
        scanf("%d",&choice);
        
        switch(choice) {
            case 1:
                top=push(stack,top);
                peek(stack,top);
                break;
            case 2:
                top=pop(stack,top);
                peek(stack,top);
                break;
            case 3: 
                peek(stack,top);
                break;
            case 4:
                printf("\nExiting the Menu\n\tThanku!!");
                break;
            default:printf("Wrong choice Entered!!");
                exit(0);
        }
     }
}