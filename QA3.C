// Evaluation of Postfix Expression using Stack

#define MAX_SIZE 30
#include<stdio.h>
#include<stdlib.h>

char stack[MAX_SIZE];
int top=-1;

void push(char ch) {
    stack[++top]=ch-'0';
}

char pop() {
    return stack[top--];
}

int check(char ch) {
    switch(ch) 
    {
        case '+':case '-':case '*':case '/':case '^':case '%':
            return 0;
    }
    return 1;
}

void perform(char c) {
    int x=(int)pop();
    switch(c) 
    {
        case '+' :
            stack[top]=(char)((int)stack[top] + x);
            break;
        case '-' :
            stack[top]=(char)((int)stack[top] - x);
            break;
        case '*' :
            stack[top]=(char)((int)stack[top] * x);
            break;
        case '/' :
            stack[top]=(char)((int)stack[top] / x);
            break;
        case '%' :
            stack[top]=(char)((int)stack[top] % x);
            break;
    }
}

int main() {
    char ch[MAX_SIZE];
    printf("\nEnter The Postfix Expression:-");
    scanf("%s",ch);
    
    for(char c:ch) {
        if(check(c)) {
            push(c);
        } else {
            perform(c);
        }
    }
    printf("The Result of Postfix Expression = %d",(int)stack[0]);
    return 0;
}