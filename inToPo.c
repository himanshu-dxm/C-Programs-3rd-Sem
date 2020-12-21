
#include<stdio.h>
#include<ctype.h>

// Structure Stack
typedef struct stack {
    char data[50];
    int top;
} s;

// push funtion of stack
void push(s*a,char x) {
    a->top+=1;
    a->data[a->top]=x;
}

// pop function of stack
char pop(s*a) {
    char x=a->data[a->top];
    a->top-=1;
    return x;
}

// function to check priority 
int priority(char x) {
    if(x=='(') {
        return 0;
    }
    if(x=='+' || x=='-') {
        return 1;
    }
    if(x=='*'||x=='/'||x=='%') {
        return 2;
    }
}

// Function to check stack is empty or not
int empty(s *a) {
    if(a->top==-1) {
        return 1;
    }
    return 0;
}

// function to return the element present at top of stack
char top(s*a) {
    return a->data[a->top];
}

// to initialize the top as -1
void init(s *a) {
    a->top=-1;
}

// The main method...
void main() {
    s a;
    char x;
    char token;
    
    init(&a);
    printf("Enter Infix Expression:");

    while((token=getchar())!='\n') {
        if(isalnum(token)) {
            printf("%c",token);
        }
        else if(token=='(') {
            push(&a,'(');
        }
        else if(token == ')') {
            while((x=pop(&a))!='(') {
                printf("%c",x);
            }
        }
        else {
            while(priority(token) <= priority(top(&a)) && !empty(&a) ) {
                x=pop(&a);
                printf("%c",x);
            }
            push(&a,token);
        }
    }
    while(!empty(&a)) {
        printf("%c",pop(&a));
    }
}