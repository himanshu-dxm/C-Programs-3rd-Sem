// PRIMITIVE OPERATIONS ON LINEAR QUEUE USING ARRRAYS
#define MAX 30

#include<stdio.h>
#include<stdlib.h>

static int f=0,r=-1;
int lq[MAX];

int lqFull() {
    if(r == MAX-1) {
        return 1;
    }
    return 0;
}

int lqEmpty() {
    if(f > r) {
        return 1;
    }
    return 0;
}

void enque() {
    if(lqFull(r)) {
        printf("\nLinear Queue Overflow\nCannot Insert Element");
        return;
    }
    int data;
    printf("\nEnter the data to be inserted:-");
    scanf("%d",&data);
    lq[++r]=data;
    printf("\nData inserted successfully!!");
}

void deque() {
    if(lqEmpty(f,r)) {
        printf("\nLinear Queue Underflow\nCannot Perform Deletion!!");
        return;
    }
    printf("\nThe data deleted is %d",lq[f]);
    f++;
}

void peek() {
    if(lqEmpty(f,r)) {
        printf("\nLinear Queue Underflow\nCannot Perform Operation");
        return;
    }
    printf("\nThe data from front to end are:-\n");
    for(int i=f;i<=r;i++) {
        printf("%d\n",lq[i]);
    }
}

void main()
{
    //int *f=0,*r=-1;
    
    int choice=-1;

    while(choice!=4) {
        printf("\nWelcome to queue implementation using arrays:-");
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