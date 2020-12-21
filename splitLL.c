// Program to split a linked list

#include<stdio.h>
#include<stdlib.h>

// STARTING OF SINGLE LINKED LIST
void singleLL() 
{
    typedef struct sll {
        int n;
        struct sll *next;
    }sll;
    sll *fronthead=NULL;
    sll *backhead=NULL;
    static int count=0;

    // FUNTION TO PUSH VALUES AT END

    sll * push(sll* fronthead) {
        sll *newptr = (sll*)malloc(sizeof(sll));
        printf("Enter A Number: ");
        scanf("%d",&newptr->n);
        
        if(fronthead==NULL) {
            fronthead=newptr;
            newptr->next=NULL;
            count++;
            return fronthead;
        }
        sll *sptr=fronthead;
        while(sptr->next != NULL) {
            sptr = sptr->next;
        }
        sptr->next = newptr;
        newptr->next = NULL;
        count++;
        return fronthead;
    }

    // FUNTION TO SPLIT INTO 2 PARTS

    sll * split(sll*fronthead) {
        if(count==1) {
            backhead=NULL;
            return backhead;
        }

        int x = count/2;
        sll* ptr=fronthead;
        for(int i=1;i<x;i++) {
            ptr=ptr->next;
        }
        backhead = ptr->next;
        ptr->next=NULL;
        return backhead;        
    }

    // FUNTION TO PRINT THE 2 PARTS

    void print(sll*fronthead,sll*backhead) {
        
        sll * fptr = fronthead;
        sll * bptr = backhead;

        printf("The First Part:-\n");
        while(fptr!=NULL) {
            printf("%d\t",fptr->n);
            fptr=fptr->next;
        }
        printf("\n The Back Part:-\n");
        while(bptr!=NULL) {
            printf("%d\t",bptr->n);
            bptr=bptr->next;
        }

    }

    printf("\nWelcome to Single Linked List Part\n");
    printf("How many values you want to enter:-");
    int x;
    scanf("%d",&x);
    fronthead=NULL;
    while(x-->0) {
        fronthead=push(fronthead);
    }
    backhead=split(fronthead);
    print(fronthead,backhead);
    
}

// STARTING OF DOUBLE LINKED LIST PART

void doubleLL() 
{
    typedef struct dll {
        int n;
        struct dll *next;
        struct dll *prev;
    }dll;
    dll *fronthead=NULL;
    dll *backhead=NULL;
    dll *fronttail=NULL;
    dll *backtail=NULL;
    static int count=0;     // TO STORE TOTAL NO OF NODES

    // FUNTION TO PUSH VALUES AFTER TAIL NODE

    dll * push(dll* fronthead) {
        dll * newptr = (dll*)malloc(sizeof(dll));
        printf("Enter A Number: ");
        scanf("%d",&newptr->n);
        
        if(fronthead==NULL) {
            fronthead=newptr;
            fronttail=newptr;
            newptr->prev=NULL;
            newptr->next=NULL;
            count++;
            return fronthead;
        }
        dll * ptr=fronttail;
        ptr->next=newptr;
        newptr->prev=ptr;
        newptr->next=NULL;
        fronttail=newptr;
        count++;
        return fronthead;
    }

    // FUNTION TO SPLIT INTO 2 PARTS

    dll * split(dll*fronthead,dll*fronttail) {
        if(count==1) {
            backhead=NULL;
            backtail=NULL;
            return backhead;
        }

        int x = count/2;
        dll* ptr=fronthead;
        for(int i=1;i<x;i++) {
            ptr=ptr->next;
        }

        backhead = ptr->next;
        backtail = fronttail;
        fronttail = ptr;
        backhead->prev=NULL;
        ptr->next=NULL;

        return backhead;        
    }

    // FUNTION TO PRINT THE 2 PARTS

    void print(dll*fronthead,dll*fronttail,dll*backhead,dll*backtail) {
        
        dll * fptr = fronthead;
        dll * bptr = backhead;

        printf("The First Part:-\n");
        while(fptr!=NULL) {
            printf("%d\t",fptr->n);
            fptr=fptr->next;
        }
        printf("\n The Back Part:-\n");
        while(bptr!=NULL) {
            printf("%d\t",bptr->n);
            bptr=bptr->next;
        }

    }

    printf("\nWelcome to Double Linked List Part\n");
    printf("How many values you want to enter:-");
    int x;
    scanf("%d",&x);
    fronthead=NULL;
    fronttail=NULL;
    while(x-->0) {
        fronthead=push(fronthead);
    }
    backhead=split(fronthead,fronttail);
    print(fronthead,fronttail,backhead,backtail);

}

// CIRCULAR LINKED LIST PART

void circularLL()
{
    typedef struct cll {
        int n;
        struct cll *next;
        struct cll *prev;
    }cll;
    cll *fronthead=NULL;
    cll *backhead=NULL;
    static int count=0;

    // TO INSERT VALUES IN CLL

    cll * push(cll* fronthead) {
        cll *newptr = (cll*)malloc(sizeof(cll));
        printf("Enter A Number: ");
        scanf("%d",&newptr->n);
        
        if(fronthead==NULL) {
            fronthead=newptr;
            newptr->prev=NULL;
            newptr->next=fronthead;
            count++;
            return fronthead;
        }
        cll *sptr=fronthead;
        do
        {
            sptr=sptr->next;
            }while(sptr->next!=fronthead);
        sptr->next = newptr;
        newptr->prev=sptr;
        newptr->next = fronthead;
        count++;
        return fronthead;
    }

    // FUNCTION TO SPLIT IT INTO 2

    cll * split(cll*fronthead) {
        if(count==1) {
            backhead=NULL;
            return backhead;
        }

        int x = count/2;
        cll* ptr=fronthead;
        for(int i=1;i<x;i++) {
            ptr=ptr->next;
        }

        backhead = ptr->next;
        backhead->prev=NULL;
        ptr->next=fronthead;
        
        cll * last = backhead;
        while(last->next!=fronthead) {
            last=last->next;
        } 
        last->next=backhead;

        return backhead;        
    }

    // FUNTION TO RPINT

    void print(cll*fronthead,cll*backhead) {
        
        cll * fptr = fronthead;
        cll * bptr = backhead;

        printf("The First Part:-\n");
        do{
            printf("%d\t",fptr->n);
            fptr=fptr->next;
        }while(fptr!=fronthead);
        printf("\n The Back Part:-\n");
        do{
            printf("%d\t",bptr->n);
            bptr=bptr->next;
        }while(bptr!=backhead);

    }

    printf("\nWelcome to Circular Linked List Part\n");
    printf("How many values you want to enter:-");
    int x;
    scanf("%d",&x);
    fronthead=NULL;
    while(x-->0) {
        fronthead=push(fronthead);
    }
    backhead=split(fronthead);
    print(fronthead,backhead);
}

// MAIN METHOD

void main() {
    printf("\t\tWhich linked list would you like to work with :- \n");
    printf("\t\t_____________________________________________");
    printf("\n");
    printf("\tEnter the number corresponding to the option\n");
    printf("\t 1. Single Linked List\n");
    printf("\t 2. Double Linked List\n");
    printf("\t 3. Circular Linked List\n");

    printf("Enter choice (1/2/3) : ");
    int ch=0;
    scanf("%d",&ch);

    switch (ch)
    {
    case 1:
        singleLL();
        break;

    case 2:
        doubleLL();
        break;

    case 3:
        circularLL();
        break;

    default:
        printf("Sorry you entered wrong choice :(");
        break;

    }
}