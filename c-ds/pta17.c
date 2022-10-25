#include<stdio.h>
#include<stdlib.h>
#define max 1005

int a[max][max];
int vi[max];

typedef struct queuenode{
    int f,r;
    int b[max];
    int size;
}*queue;

int bfs(int v,queue q,int p){
    vi[v]=1;int c=1;int lever=0;int last;int tail;
    last=v;
    q->b[q->r++]=v;q->size++;
    while(q->size!=0){
        v=q->b[q->f++];q->size--;
        for(int j=1;j<=p;j++)
            if(!vi[j]&&a[v][j]){
                vi[j]=1;
                q->b[q->r++]=j;q->size++;c++;tail=j;
            }
        if(v==last){lever++;last=tail;}
        if(lever==6)break;
    }
    return c;
}
int main(){
    int p,e,w,j;
    scanf("%d %d",&p,&e);
    for(int i=1;i<=p;i++)
        for(int j=1;j<=p;j++){
            //if(i==j) a[i][j]=1;
            a[i][j]=0;
        }
    for(int i=0;i<e;i++){
        scanf("%d %d",&w,&j);
        a[w][j]=1;a[j][w]=1;
    }
    for(int i=1;i<=p;i++){
        for(int j=1;j<=p;j++)
            vi[j]=0;
        queue q=(queue)malloc(sizeof(struct queuenode));
        q->f=q->r=0;
        q->size=0;
        int c=bfs(i,q,p);
        double b=((double)c/(double)p)*100;
        printf("%d: %.2lf%%\n",i,b);
    }
    return 0;
}