#include<stdio.h>
#define max 100
int a[max][max];
int f[max][max];

void seta(int p){
    for(int i=0;i<p;i++)
        for(int j=0;j<p;j++){
            if(i==j) a[i][j]=0;
            else a[i][j]=100000;
        }
}

void setf(int p){
    for(int i=0;i<p;i++)
        for(int j=0;j<p;j++)
            f[i][j]=a[i][j];
}

void floyd(int p){
    for(int k=0;k<p;k++)
        for(int i=0;i<p;i++)
            for(int j=0;j<p;j++)
                if(f[i][j]>f[i][k]+f[k][j])
                    f[i][j]=f[i][k]+f[k][j];
}

int main(){
    int p,e,e1,e2,d;
    scanf("%d %d",&p,&e);
    seta(p);
    for(int i=0;i<e;i++){
        scanf("%d %d %d",&e1,&e2,&d);
        a[e1-1][e2-1]=d;
        a[e2-1][e1-1]=d;
    }
    setf(p);
    floyd(p);
    int min=100000,maxd,mind;
    for(int i=0;i<p;i++){
        maxd=0;
        for(int j=0;j<p;j++){
            if(maxd<f[i][j])
                maxd=f[i][j];
        }
        if(maxd==100000){printf("0\n");return 0;}
        if(maxd<min){
             min=maxd;
             mind=i+1;
        }
    }
    printf("%d %d",mind,min);
    return 0;
}