// Queue implementation using SLL

#include<stdio.h>
#include<stdlib.h>

typedef struct Queue {
    int data;
    struct Queue *next;
}q;

q *f=NULL;
q *r=NULL;

int q_Empty() {
    if(r==NULL || f == NULL) {
        return 1;
    }
    return 0;
}

void enque() {
    q *temp = (q *)malloc(sizeof(q));
    printf("\nEnter data to be inserted:");
    scanf("%d",&temp->data);
    if(f==NULL) {
        f=temp;
    }
    temp->next=r;
    r=temp;
}

void deque() {
    if(q_Empty()) {
        printf("\nQueue Underflow!!");
        return;
    }
    printf("\nThe data to be deleted is:\n");
    printf("%d",f->data);
    q *temp=f;
    f=f->next;
    free(temp);
}

void peek() {
    if(q_Empty()) {
        printf("\nQueue is Empty!\nNothing to show!!");
        return;
    }
    printf("\nThe data from front to end are:\n");
    for(q *i=f;i!=r;i=i->next) {
        printf("%d",i->data);
    }
}

void main() {
    int choice=-1;

    while(choice!=4) {
        printf("\nWelcome to queue implementation using linked lists:-");
        printf("\nThe Operations are:-");
        printf("\n1->Insert an Element");
        printf("\n2->Delete an Element");
        printf("\n3->Display the Queue Contents");
        printf("\n4->Exit the Menu");
        printf("\nEnter your choice:-");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                enque();
                peek();
                break;
            case 2:
                deque();
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