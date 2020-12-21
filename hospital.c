#include<stdio.h>
#include<stdlib.h>

typedef struct hospital {
    char patientName[30];
    double amount;
    struct hospital * next;
}hospital;
hospital* head;

//To Print the patient names
void printPatientName()
{
    if(head==NULL) {
        printf("Empty List");
    }
    else
    {
        hospital * pointer;
        pointer=head;
        while(pointer!=NULL)
        {
            printf("Patient Name:- %s",pointer->patientName);
            printf("Amount To Be Paid:- %d",pointer->amount);
            pointer = pointer->next;
        }                
    }
    
}// eof

//To create new patient detail
hospital* createAccount(hospital * ptr)
{
    hospital * newAcnt = (hospital *)malloc(sizeof(hospital));
    printf("Enter Patient Name:- ");
    scanf("%s",newAcnt->patientName);
    printf("Enter Amount:- ");
    scanf("%d",&newAcnt->amount);

    newAcnt->next = NULL;
    return newAcnt;
}// eof

//TO INSERT AT BGINNING
hospital* pushBeginning(hospital * ptr) 
{
    hospital* temp = createAccount(ptr);
    //hospital * head;
    if(head==NULL)
    {
        head=temp;
    }else
    {
        temp->next = head;
        head = temp;
    }
    return head;    
}// eof

//TO INSERT AT END
hospital * pushEnd(hospital * head)
{
    if(head==NULL)
    {
        return pushBeginning(head);
    }
    else
    {
        hospital* nav;;
        nav=head;
        while(nav->next != NULL)
        {
            nav = nav->next;
        }
        hospital * temp = createAccount(NULL);
        nav->next = temp;
        return head;
    }
    
}// eof

void main() 
{
    head=NULL;
    head=pushBeginning(head);
    printPatientName();
    head=pushBeginning(head);
    printPatientName();
    head=pushEnd(head);
    printPatientName();
    head=pushBeginning(head);
    printPatientName();
    head=pushEnd(head);
    printPatientName();head=pushEnd(head);
    printPatientName();
    head=pushBeginning(head);
    printPatientName();    
}