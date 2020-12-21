// Circular Queue using Arrays

#define MAX_SIZE 30
#include<stdio.h>
#include<stdlib.h>

int cq[MAX_SIZE];   
int f=0,r=-1;

int cq_Full() {
    if((r-f+1)==MAX_SIZE) {
        return 1;
    }
    return 0;
}

int cq_Empty() {
    if(f==-1 || ((r-f)<0)) {
        return 1;
    }
    return 0;
}

void c_enque() {
    if(cq_Full()) {
        printf("Circular Queue Overflow\nCannot insert data");
        return;
    }
    printf("\nEnter data to be inserted:");
    int x;
    scanf("%d",&x);
    r=(r+1)%MAX_SIZE;
    cq[r%MAX_SIZE]=x;
    printf("\nData Inserted Successfully!!");
}

void c_deque() {
    if(cq_Empty()) {
        printf("\nCircular Queue contains no Element!\n");
        return;
    }
    printf("\nThe data Popped of is\t");
    printf("%d",cq[f%MAX_SIZE]);
    f=(f+1)%MAX_SIZE;
}

void c_peek() {
    if(cq_Empty()){ 
        printf("\nCircular Queue contains no Element!\n");
        return;
    }
    printf("\nThe Elements are:\n");
    for(int i=f;i<r;i=(i+1)%MAX_SIZE) {
        printf("%d\n",cq[i]);
    }
}

void main() {
    int choice=-1;

    while(choice!=4) {
        printf("\nWelcome to Circular Queue implementation using arrays:-");
        printf("\nThe Operations are:-");
        printf("\n1->Insert an Element");
        printf("\n2->Delete an Element");
        printf("\n3->Display the Queue Contents");
        printf("\n4->Exit the Menu");
        printf("\nEnter your choice:-");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                c_enque();
                c_peek();
                break;
            case 2:
                c_deque();
                c_peek();
                break;
            case 3: 
                c_peek();
                break;
            case 4:
                printf("\nExiting the Menu\n\tThanku!!");
                break;
            default:printf("Wrong choice Entered!!");
                exit(0);
        }
     }
}