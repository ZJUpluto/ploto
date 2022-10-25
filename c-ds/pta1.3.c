//写程序，首先传函数时只需要传函数名即可，定义数组时，里面的值应该被确认过

#include<stdio.h>

int max3(int a,int b,int c){
    return a > b ? a > c ? a : c : b > c ? b : c;
}

int sum(int b[],int left, int right){
    int maxleft,maxright;
    int lef,righ;
    int center,i;
    int maxl,maxr;

    if(left==right){
        if(b[left]<0) return 0;
        else return b[left];
    }

    center=(left+right)/2;

    maxl=sum(b,left,center);
    maxr=sum(b,center+1,right);

    lef=0;
    maxleft=0;
    for(i=center;i>=left;i--){
        lef+=b[i];
        //if(lef<0) lef=0;
        if(lef>maxleft) maxleft=lef;
    }

    righ=0;
    
    maxright=0;
    for(i=center+1;i<=right;i++){
        righ+=b[i];
        //if(righ<0) righ=0;
        if(righ>maxright) maxright=righ;
    }

    return max3(maxl,maxr,maxright+maxleft);
}


int f( int b[] , int N ){
    return sum(b,0,N-1);
}

int main(void){
    int N;
    scanf("%d", &N );
    int b[N];
    for(int k=0;k<=N-1;k++)
        scanf("%d", &b[k]);
    printf("%d\n",f(b,N));
    return 0;
}