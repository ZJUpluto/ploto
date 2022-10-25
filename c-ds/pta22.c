#include<stdio.h>
#define max 100
#define inf 10000
int m[max][max],in[max],out[max],vi[max],er[max];
int early(int w,int p){
    int maxx=0;
    for(int v=0;v<p;v++)
        if(m[v][w]!=inf&&m[v][w]+er[v]>maxx)
            maxx=m[v][w]+er[v];
    return maxx;
}
int last(int p){
    int maxa=0;
    for(int i=0;i<p;i++)
        if(out[i]==0&&er[i]>maxa)
            maxa=er[i];
    return maxa;
}
int main(){
    int p,e,i,j,w,p1,p2;
    scanf("%d %d",&p,&e);
    for(i=0;i<p;i++)
        for(j=0;j<p;j++)
            m[i][j]=inf;
    for(i=0;i<e;i++){
        scanf("%d %d %d",&p1,&p2,&w);
        m[p1][p2]=w;
    }
    for(i=0;i<p;i++)
        for(j=0;j<p;j++)
            if(m[i][j]!=inf){
                in[j]++;
                out[i]++;
            }
    int vc=0;
    while(1){
        int v=-1;
        for(i=0;i<p;i++)
            if(!vi[i]&&!in[i]){
                vi[i]=1;
                v=i;
                break;
            }
        if(v==-1) break;
        er[v]=early(v,p);
        for(int w=0;w<p;w++)
            if(m[v][w]!=inf)
                in[w]--;
        vc++;
    }
    if(vc==p) printf("%d",last(p));
    else printf("Impossible");
    return 0;
}