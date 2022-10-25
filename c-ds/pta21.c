#include<stdio.h>
#define max 1000
#define inf 10000
int m[max][max],d[max];

int main(){
    int p,e,p1,p2,dd;
    scanf("%d %d",&p,&e);
    for(int i=0;i<p;i++)
        for(int j=0;j<p;j++)
            m[i][j]=inf;
    for(int i=0;i<e;i++){
        scanf("%d %d %d",&p1,&p2,&dd);
        m[p1-1][p2-1]=dd;
        m[p2-1][p1-1]=dd;
    }
    int vc=0;
    int money=0;
    for(int i=0;i<p;i++)
        d[i]=m[0][i];
    d[0]=0;
    vc++;
    while(1){
        int min=inf,minv;
        for(int v=0;v<p;v++)
            if(d[v]&&d[v]<min){
                min=d[v];
                minv=v;
            }
        if(min==inf) break;
        int v=minv;
        vc++;money+=d[v];d[v]=0;
        for(int w=0;w<p;w++){
            if(d[w]&&d[w]>m[v][w])
                d[w]=m[v][w];
        }
    }
    if(vc==p) printf("%d",money);
    else printf("-1");
}