#include<stdio.h>
void f( int a[] , int N , int left , int right){
    int max=-1;
    int now =0;
    for(int i=0;i<N;i++){
        now += a[i];
        if(now<0)
            now = 0;
        else if(now>max){
            max = now;
            right=i;}
    }
    max=-1;
    now =0;
    for(int i=right;i>=0;i--){
        now += a[i];
        if(now<0)
            now = 0;
        else if(now>=max){
            max = now;
            left=i;}
    }
    if(max<0){
        max=0;
        left=0;
        right=N-1;
    }
    printf("%d %d %d\n",max,a[left],a[right]);
}

int main(void){
    int N,left,right;
    left=right=0;
    scanf("%d", &N );
    int a[N];
    for(int i=0;i<N;i++)
        scanf("%d", &a[i]);
    f(a,N,left,right);
    return 0;
}