// Stack using Linked List

#include<stdio.h>
#include<stdlib.h>

typedef struct Stack {
    int data;
    struct Stack *next;
}Stack;

Stack *top = NULL;

Stack* newNode() {
    Stack *temp=(Stack *)malloc(sizeof(Stack));
    temp->data=0;
    temp->next=NULL;
    return temp;
}

int stack_empty() {
    if(top==NULL) {
        return 1;
    }
    return 0;
}

void push() {
    printf("\nEnter data to be inserted:");
    Stack * temp=newNode();
    scanf("%d",&temp->data);
    temp->next=top;
    if(top==NULL) {
        top=temp;
        return;
    }
    top=temp;    
}

void pop() {
    if(stack_empty()) {
        printf("Stack Underflow!!!");
        return;
    }
    printf("\nThe data popped of is\n");
    printf("%d",top->data);
    Stack * temp = top;
    top=top->next;
    free(temp);
}

void peek() {
    if(stack_empty()) {
        printf("Stack Empty ! \nNothing to show!!");
        return;
    }
    Stack * temp = top;
    printf("\nThe data Elements are:\n");
    while(temp!=NULL) {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}

void main() {
     int choice=-1;
     while(choice!=4) {
        printf("\nWelcome to stack implementation using linked lists:-");
        printf("\nThe Operations are:-");
        printf("\n1->Insert an Element");
        printf("\n2->Delete an Element");
        printf("\n3->Display the Stack Contents");
        printf("\n4->Exit the Menu");
        printf("\nEnter your choice:-");
        scanf("%d",&choice);
        
        switch(choice) {
            case 1:
                push();
                peek();
                break;
            case 2:
                pop();
                peek();
                break;
            case 3: 
                peek();
                break;
            case 4:
                printf("\nExiting the Menu\n\tThanku!!");
                break;
            default:printf("Wrong choice Entered!!");
                exit(0);
        }
     }
}