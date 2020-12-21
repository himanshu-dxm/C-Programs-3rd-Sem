// C rpogram for Fibonacci Series
#include<stdio.h>

// A function to print the nth term of series
int Fibo(int n) {
    if(n<=1) {
        return 0;
    } 
    if(n==2) {
        return 1;
    }
    return (Fibo(n-2)+Fibo(n-1));
}

// Funtion to print sum of n terms of Fibonacci Series
int sumFibo(int n) {
    if(n<=1) {
        return 0;
    } 
    if(n==2) {
        return 1;
    }
    return (Fibo(n)+sumFibo(n-1));
}

// Function to Print the series upto nth term
void printFibo(int n) {
    int i=0;
    while(++i<=n) {
        printf("%d ",Fibo(i));
    }
}

// The main method..
void main() {
    int n;
    printf("Enter Number of Terms:");
    scanf("%d",&n);
    printf("\nThe %d term=%d",n,Fibo(n));
    printf("\n\nThe sum of %d terms=%d",n,sumFibo(n));
    printf("\n\nThe series upto %d terms=\n",n);
    printFibo(n);
}