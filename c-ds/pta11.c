#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define max 1000
int a[max],b[max];

int cmp(const void *a, const void *b){
    return *(int*)a- *(int*)b;
}

int min(int a,int b){
    return a>b?b:a;
}

int length(int d){
    int h=(int)log2(d+1);
    int x=pow(2,h-1);
    x=min(x,d+1-pow(2,h));
    return x+pow(2,h-1)-1;
}


void solve(int l,int r,int root){
    int d=r-l+1;
    if(d==0) return;
    int le=length(d);
    b[root]=a[le+l];
    int ll=root*2+1;
    int lr=root*2+2;
    solve(l,l+le-1,ll);
    solve(l+le+1,r,lr);
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),cmp);
    solve(0,n-1,0);
    for(int i=0;i<n-1;i++)
        printf("%d ",b[i]);
    printf("%d",b[n-1]);
    return 0;
}