#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 30
int pre[max],in[max],post[max];

typedef struct nodes{
    int a[max];
    int top;
}*stack;

void solve(int pl,int il,int tl,int n){
    int i,left,right;
    if(n==0) return;
    if(n==1) {post[tl]=pre[pl];return;}
    post[tl+n-1]=pre[pl];
    for(i=0;i<n;i++)
        if(in[il+i]==pre[pl]) break; 
    solve(pl+1,il,tl,i);
    solve(pl+i+1,il+i+1,tl+i,n-i-1);
}
int main(){
	int i,j=0,k=0,x,n;
	int flag = 1;
	char str[10];	
	scanf("%d",&n);
    stack s=malloc(sizeof(struct nodes));
    s->top=-1;
	for(i=0; i<2*n; i++){
		scanf("%s",str);
		if(strcmp(str,"Push") == 0){
			scanf("%d",&x);
			pre[j++] = x;
			s->a[++(s->top)]=x;
		}else in[k++] = s->a[(s->top)--];        
	}
    solve(0,0,0,n);
    for(i=0;i<n;i++){
    if(flag) {printf("%d",post[i]); flag=0;}
    else printf(" %d",post[i]);
    }
    return 0;
}