#include<stdio.h>
#include<stdlib.h>
#define max 11
int b[max],d[max];
typedef struct gnode{
    int p,e;
    int a[max][max];
}*graph;
typedef struct qnode{
    int f,r;
    int size;
    int b[max];
}*queue;
graph createmap(int m,int n){
    int w,j;
    graph g=(graph)malloc(sizeof(struct gnode));
    g->p=m;g->e=n;
    for(w=0;w<m;w++)
        for(j=0;j<m;j++)  g->a[w][j]=0;
    for(int i=0;i<n;i++){
        scanf("%d %d",&w,&j);
        g->a[w][j]=1;
        g->a[j][w]=1;
    }
    return g;
}
queue createqueue(){
    queue q=(queue)malloc(sizeof(struct qnode));
    q->f=q->r=-1;
    q->size=0;
    return q;
}
void dfs(graph g,int i){
    d[i]=1;
    printf("%d ",i);
    for(int j=0;j<=g->p;j++)
        if((g->a[i][j])&&(!d[j]))
            dfs(g,j);
}
void enq(int a,queue q){
    q->b[++q->r]=a;
    q->size++;
}
int deq(queue q){
    q->size--;
    return q->b[++q->f];
}
void bfs(graph g,int i,queue q){
    printf("%d ",i);
    b[i]=1;
    enq(i,q);
    while(q->size){
        int i=deq(q);
        for(int j=0;j<g->p;j++)
            if((g->a[i][j])&&(!b[j])){
                printf("%d ",j);
                b[j]=1;
                enq(j,q);
            }
        
    }
}
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    graph g=createmap(m,n);
    queue q=createqueue();
    
    for(int i=0;i<m;i++)
        if(!d[i]){
            printf("{ ");
            dfs(g,i);
            printf("}\n");
        }
    for(int i=0;i<m;i++)
        if(!b[i]){
            printf("{ ");
            bfs(g,i,q);
            printf("}\n");
        }
    return 0;
}