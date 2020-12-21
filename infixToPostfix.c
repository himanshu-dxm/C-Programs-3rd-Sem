// C Program to convert infix expression to potfix using stack

#include<stdio.h>
#include<ctype.h>
typedef struct Stack {
    char c[30];
} s;

void push(char x,int top,s *a) {
    a->c[++top]=x;
}

char pop(int top,s *a) {
    return a->c[top--];
}

int priority(char x) {
    if(x=='(')
        return 0;
    if(x=='+' || x=='-')
        return 1;
    if(x=='*' || x=='/' || x=='%')
        return 2;

    return 3;
}

int empty() {
    if(top==-1) {
        return 1;
    }
    return 0;
}

void startOperation(char ch[50],int top) {
    s *a;
    for(int i=0;ch[i]!='\0';i++) {
        if(isalnum(ch[i])) {
            printf("%c",ch[i]);
        }
        else if(ch[i]=='(') {
            push('(',top,a);
        } 
        else if(ch[i]==')') {
            while(pop(top,a)!='(') {
                printf("%c",ch[i]);
            }
        }
        else {
            while(priority(ch[i])<=priority(top) && !empty()) {
                printf("%c",pop(top,a));
            }
            push(ch[i],top,a);
        }
    }
    while(!empty()) {
        printf("%c",pop(top,a));
    }
}

void getEntry(int top) {
    printf("Enter the Expression:-");
    char ch[50];
    scanf("%s",ch);
    startOperation(ch,top);
}

void main() {
    int top=-1;
    getEntry(top);

}