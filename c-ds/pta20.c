#include<stdio.h>
#define max 500
#define inf 10000
int dist[max],visit[max],money[max];

struct map{
    int l,m;
}a[max][max];

int main(){
    int p,e,m,n;
    int p1,p2,ll,mm;
    scanf("%d %d %d %d",&p,&e,&m,&n);
    for(int i=0;i<p;i++)
        for(int j=0;j<p;j++)
            a[i][j].l=a[i][j].m=inf;
    for(int i=0;i<e;i++){
        scanf("%d %d %d %d",&p1,&p2,&ll,&mm);
        a[p1][p2].l=a[p2][p1].l=ll;
        a[p1][p2].m=a[p2][p1].m=mm;
    }
    int v;
    for(int v=0;v<p;v++){
        dist[v]=a[m][v].l;
        money[v]=a[m][v].m;
        visit[v]=0;
    }
    dist[m]=0;
    money[m]=0;
    visit[m]=1;
    while(1){
        int min=inf;int minv;
        for(int v=0;v<p;v++)
        if(!visit[v]&&dist[v]<min){
            min=dist[v];
            minv=v;
        }
        if(min==inf) break;
        v=minv;
        visit[v]=1;
        for(int w=0;w<p;w++){
            if(!visit[w]&&dist[w]>dist[v]+a[v][w].l){
                dist[w]=dist[v]+a[v][w].l;
                money[w]=money[v]+a[v][w].m;
            }
            else if(!visit[w]&&dist[w]==dist[v]+a[v][w].l&&money[w]>money[v]+a[v][w].m){
                //dist[w]=dist[v]+a[v][w].l;
                money[w]=money[v]+a[v][w].m;
            }
        }
    }
    printf("%d %d",dist[n],money[n]);
    return 0;
}