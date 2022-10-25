#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    int now=0,max=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        now+=a[i];
        if(now<0) now=0;
        if(now>max) max=now;
    }
    printf("%d",max);
    return 0;
}