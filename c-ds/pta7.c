#include<stdio.h>
#include<stdlib.h>
#define max 10
#define Null -1
#define maxq 11
struct tree{
    int l;
    int r;
}t[max];

struct Queue{
    int a[maxq];
    int fr;
    int re;
};

typedef struct Queue *queue;

queue create(){
    queue q=(queue)malloc(sizeof(struct Queue));
    q->fr=q->re=0;
    return q;
}

void add(queue q,int a){
    if(q->fr==(q->re+1)%maxq) return;
    q->re=(q->re+1)%maxq;
    q->a[q->re]=a;
}

int delete(queue q){
    q->fr=(q->fr+1)%maxq;
    return q->a[q->fr];
}

int empty(queue q){
    if(q->fr==q->re) return 1;
    else return 0;
}


void listleaves(int root){
    queue q;
    int num;
    int flag=0;
    if(root==-1) return;
    q=create();
    add(q,root);
    while(!empty(q)){
        num=delete(q);
        if(t[num].l==-1&&t[num].r==-1){
            if(flag) printf(" ");
            printf("%d",num);
            flag=1;
        }
        if(t[num].l!=-1) add(q,t[num].l);
        if(t[num].r!=-1) add(q,t[num].r);
    }
}

int build(){
    int i,n;
    char le,ri;
    scanf("%d\n",&n);
    if(n==0) return -1;
    int b[max];
    for(i=0;i<n;i++) b[i]=0;
    for(i=0;i<n;i++){
        scanf("%c %c\n",&le,&ri);
        if(le!='-'){
            t[i].l=le-'0';
            b[t[i].l]=1;
        }
        else t[i].l=-1;
        if(ri!='-'){
            t[i].r=ri-'0';
            b[t[i].r]=1;
        }
        else t[i].r=-1;
    }
    for(i=0;i<n;i++)  
        if(b[i]==0) break;
    return i;
}

int main(){
    int root;
    root=build();
    listleaves(root);
    return 0;
}