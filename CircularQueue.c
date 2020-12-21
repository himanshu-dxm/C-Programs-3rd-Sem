
#include<stdio.h>

#define MAX_SIXE 50

int cqfull(int c) {
    if(c==MAX_SIXE) {
        return 1;
    }
    return 0;
}

int cqempty(int c) {
    if(c==0) {
        return 1;
    }
    return 0;
}

void insert_rear(int item,int cq[],int *r,int *c) {
    if(cqfull(*c)) {
        printf("Queue Overflow!!\n");
    }

    *r=(*r+1)%MAX_SIXE;
    cq[*r]=item;
    *c=*c+1;
}

void delete_front(int cq[],int *f,int *c) {
    *f=(*f+1)%MAX_SIXE;
    *c=*c-1;
}

void display(int cq[],int f,int c) {
    if(cqempty(c)) {
        printf("Queue Empty\n");
        return;
    }
    printf("\nThe contents are:\n");

    for(int i=f;c!=0;i=(i+1)%MAX_SIXE,c--) {
        printf("%d\t",cq[i]);
    }
}

void main() {
    int q[MAX_SIXE]={1,2,3,4};
    int f=0,r=3;
    int count=4;

    display(q,f,count);
    insert_rear(5,q,&r,&count);
    insert_rear(6,q,&r,&count);
    insert_rear(7,q,&r,&count);
    insert_rear(8,q,&r,&count);
    insert_rear(9,q,&r,&count);
    insert_rear(10,q,&r,&count);
    insert_rear(11,q,&r,&count);
    
    display(q,f,count);

    delete_front(q,&f,&count);
    delete_front(q,&f,&count);
    delete_front(q,&f,&count);
    
    display(q,f,count);
}