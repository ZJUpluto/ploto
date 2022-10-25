#include<stdio.h>
#include<stdlib.h>
#define max 1000

typedef struct stacknode{
    int a[max];
    int top;
}*stack;

int judge(int b[],int m,int n){
    stack s=(stack)malloc(sizeof(struct stacknode));
    s->top=-1;
    int c=0;
    for(int i=1;i<=n;i++){
        if(s->top==m-1) return 0;
        else s->a[++s->top]=i;
        while(s->a[s->top]==b[c]&&s->top>=0){c++;s->top--;}
    }
    if(s->top==-1) return 1;
    else return 0;
}

int main(){
    int m,n,k,b[max];
    scanf("%d %d %d",&m,&n,&k);
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&b[j]);
        }
        if(judge(b,m,n)) printf("YES\n");
        else printf("NO\n");
    }
}