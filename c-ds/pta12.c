#include<stdio.h>
#define max 10001
#define min -10001

int main(){
    int m,n,k,s,j=0;
    int a[max];
    a[0]=min;
    scanf("%d %d",&m,&n);
    for(int i=0;i<m;i++){
        scanf("%d",&k);
        for(s=++j;a[s/2]>k;s=s/2)
            a[s]=a[s/2];
        a[s]=k;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&k);
        printf("%d",a[k]);
        for(j=k/2;j>=1;j=j/2){
            printf(" %d",a[j]);
        }
        printf("\n");
    }
    return 0;
}