//libraries
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

//defination of structure lib
typedef struct lib
{
    char Book_name[20];
    price Price_of_book;
    struct lib *Next_item;
}lib;
// head initialized
lib *Head;
//let TOTAL be the global varaible for the total sum of the price of all elements
float TOTAL=0.0;
//Create the new node

lib * Create_new_Entry(){
    //give memory to new node
    lib *New_Book=(lib *)malloc(sizeof(lib *));
    //enter name and price
    printf("ENTER THE NAME OF BOOK:\n");
    scanf("%s",New_Book->Book_name);
    printf("ENTER THE PRICE OF THE BOOK:\n");
    scanf("%f",&New_Book->Price_of_book); 
    //attach the new to next
    New_Book->Next_item=NULL;
    return New_Book;
}
/*
//search the list

lib * Search_the_LL(lib *Head,char *Name_of_Book)
{
    lib *Search_ptr=Head;
    if(Head==NULL)
    {
        return NULL;
    }
    else{
        while(Search_ptr!=NULL){
            if(!strcmp(Search_ptr->Book_name,Name_of_Book)){
                return Search_ptr;
            }
            else
            {
                Search_ptr=Search_ptr->Next_item;
            }        
        } 
    }
    return NULL;
}
*/
// insert to LL

lib *Insert(lib *Head){
    //initialze head to local variable
    lib *PTR=Head;
    if(PTR==NULL){
        //create the node by calling func
        lib *New_Entry=Create_new_Entry();
        //update value of head with new value
        PTR=New_Entry;
        //update the total
        TOTAL+=New_Entry->Price_of_book;
        return PTR;
    }
    else
    {
        lib *New_Entry=Create_new_Entry();
        while(PTR->Next_item!=NULL){
            PTR=PTR->Next_item;
        }
        //update the total
        TOTAL+=New_Entry->Price_of_book;
        PTR->Next_item=New_Entry;
        return PTR;
    }
}

//main
int main()
{
    Head=NULL;
    int num_books;
    printf("ENTER THE NUMBER OF BOOKS TO BE PURCHASED:\n");
    scanf("%d",&num_books);
    for (int i=0;i<num_books;i++){
        Head=Insert(Head);
    }
    printf("THE TOTAL PRICE OF THE BOOKS IS:  %d\n",TOTAL);
    float AVG_=TOTAL/num_books;
    printf("THE TOTAL PRICE OF THE BOOKS IS:  %.3f\n",AVG_);
    return 0;
}
