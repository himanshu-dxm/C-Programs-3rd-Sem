// Binary Search using Recursion

#include<stdio.h>

int binSearch(int arr[],int l,int r,int x) {
    int mid=(l+r)/2;

    if(arr[mid]==x) {
        return mid;
    } else if(arr[mid]<x) {
        return binSearch(arr,mid+1,r,x);
    } else {
        return binSearch(arr,l,mid-1,x);
    }
    return -1;
}

void main() {
    int arr[10],x;
    printf("Enter 10 array Elements:-\n");
    for(int i=0;i<10;i++) {
        scanf("%d",&arr[i]);
    }
    printf("Enter data to be searched: ");
    scanf("%d",&x);
    int l=0,r=9;
    int ind=binSearch(arr,l,r,x);
    if(ind!=-1) {
        printf("Value Found At:%d position",ind+1);
    } else {
        printf("Data not found the array:(");
    }
}