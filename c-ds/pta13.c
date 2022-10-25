#include<stdio.h>


int find(int a[],int i){
    if(a[i]<0) return i;
    else return a[i]=find(a,a[i]);
}

void input(int a[]){
    int r1,r2,x,y;
    scanf("%d %d",&x,&y);
    r1=find(a,x-1);
    r2=find(a,y-1);
    if(r1!=r2)
        a[r1] = r2;
}




void check(int a[]){
    int r1,r2,x,y;
    scanf("%d %d",&x,&y);
    r1=find(a,x-1);
    r2=find(a,y-1);
    if(r1==r2) printf("yes\n");
    if(r1!=r2) printf("no\n");
}

void judge(int a[],int n){
    int cnt=0;
    for(int i=0;i<n;i++)
        if(a[i]<0) cnt++;

    if(cnt==1) printf("one\n");
    if(cnt>1) printf("%d is\n",cnt);
}


int main(void){
    int a[10];
    int n;
    char in;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        a[i]=-1;
    do {
        scanf("%c",&in);
        switch (in){
            case 'I' :input(a);break;
            case 'C' :check(a);break;
            case 'S' :judge(a,n); break;
        }
    } while(in != 'S');
    return 0;
}