// A Grocery Store Billing Management System

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Grocery Structure Definition
typedef struct Grocery {
    char item_name[30]; // To Store Name of Item
    float amount; // To Store Price of Item
    struct Grocery * next; // A Next Pointer
}Grocery; 
Grocery *head;
Grocery *sptr; 

static int numberOfNodes = 0; // TO STORE TOTAL NUMBER OF NODES

//  TO INSERT AT END IN LINKED LIST
void insertEnd(Grocery * head,Grocery * newptr) {
    
    sptr=head;
    
    while(sptr->next != NULL) {
        sptr = sptr->next;
    }
    
    sptr->next = newptr;
    
    newptr->next = NULL;
}

// TO CREATE A NEW NODE
Grocery* createNew(Grocery * head) {
    
    Grocery * newptr = (Grocery *) malloc(sizeof(Grocery));
    
    printf("Enter Item Name: ");
    gets(newptr->item_name);
    
    printf("Enter Amount : ");
    scanf("%f",&newptr->amount);
    
    while ((getchar()) != '\n');
    
    if(head==NULL) {
        head=newptr;
        newptr->next=NULL;
    } else {
        insertEnd(head,newptr);
    }
    
    numberOfNodes++;
    
    return head;
}


// TO CALCULATE TOTAL AMOUNT
float calcTotalAmount(Grocery * head) {
    sptr=head;
    float tot=0.0;
    
    while(sptr != NULL) {
        tot = tot + sptr->amount;
        sptr = sptr->next;
    }
    
    return tot;
}


// THE MAIN METHOD
void main() {
    
    head = NULL;
    
    int ch=1;
    
    printf("Welcome To Grocery Shop\n");
    head=createNew(head);
    
     while(ch!=0) {
         
         printf("Do u want to Purchase More(1/0):-");
         scanf("%d",&ch);
         while ((getchar()) != '\n');
         if(ch==0) {
             break;
         }
         head=createNew(head);
     }
    
     float totAmount = calcTotalAmount(head);
     printf("Total Amount To Be Paid = %f",totAmount);

     float average = totAmount/numberOfNodes;
     printf("Average Amount = %f" , average);

}