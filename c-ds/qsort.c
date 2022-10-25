#include<stdio.h>
#include<stdlib.h>

void swap(int*a,int*b){
    int t=*a;
    *a=*b;
    *b=t;
}

int mid(int a[],int l,int r){
    int c=(l+r)/2;
    if(a[l]>a[r])
    swap(&a[l],&a[r]);
    if(a[l]>a[c])
    swap(&a[l],&a[c]);
    if(a[c]>a[r])
    swap(&a[r],&a[c]);
    swap(&a[c],&a[r-1]);
    return a[r-1];
}

void quick(int a[],int l,int r){
    int pivot,low,high;
    pivot=mid(a,l,r);
    low=l;high=r-1;
    while(1){
        while(a[++low]<pivot);
        while(a[--high]>pivot);
        if(low<high) swap(&a[low],&a[high]);
        else break;
    }
    swap(&a[low],&a[r-1]);
    quick(a,l,low-1);
    quick(a,low+1,r);
}
void quick_sort(int a[],int n){
    quick(a,0,n-1);
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);

    quick_sort(a,n);

    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
    return 0;
}