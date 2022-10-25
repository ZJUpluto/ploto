#include<stdio.h>
#include<math.h>
#define max 105
int v[max]={0};
int m[max][max]={0};
int ans;
typedef struct pointnode{
    int x,y;
}point;

int distant(point p1,point p2,double d){
    double dis=sqrt(pow((p1.x-p2.x),2)+pow((p1.y-p2.y),2));        
	if(dis<=d)	return 1;
    else return 0;
}

int dfs(int po,point p[],int n,int d){
    v[po]=1;
    if(p[po].x>=50-d||p[po].y>=50-d)  ans=1;
    if(ans==0){
        for(int i=0;i<n;i++)
        if(m[po][i]&&!v[i]){
            ans=dfs(i,p,n,d);
            if(ans==1) break;
        }
    }
    return ans;
}


int main(){
    int n,d;
    scanf("%d %d",&n,&d);
    point p[max];
    p[0].x=p[0].y=0;
    n++;
    for(int i=1;i<n;i++)
        scanf("%d %d",&(p[i].x),&(p[i].y));
    for(int i=0;i<n;i++){
        if(distant(p[0],p[i],d+7.5))  m[0][i]=1;
        else m[0][i]=0;
    }
    for(int i=1;i<n;i++)
        for(int j=0;j<n;j++){
            if(distant(p[i],p[j],d))  m[i][j]=1;
            else m[i][j]=0;
        }
    if(dfs(0,p,n,d)) printf("Yes\n");
    else printf("No\n");
    return 0;
}