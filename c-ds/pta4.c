#include<stdio.h>
#define max 100001

int main(){
    int num[max];
    int add[max];
    int link[max];
    int f,n,k;
    scanf("%d %d %d",&f,&n,&k);
    for(int i=0;i<n;i++){
        int ad,nu,li;
        scanf("%d %d %d",&ad,&nu,&li);
        num[ad]=nu;
        add[ad]=li;
    }
    int count=0;
    while(f!=-1){
        link[count++]=f;
        f=add[f];
    }
    for(int i=0;i<count-count%k;i+=k){
        for(int j=0;j<k/2;j++){
            int t=link[i+j];
            link[i+j]=link[k+i-j-1];
            link[k+i-j-1]=t;
        }
    }
    for(int i=0;i<count-1;i++)
		printf("%05d %d %05d\n",link[i],num[link[i]],link[i+1]);
	printf("%05d %d -1\n",link[count-1],num[link[count-1]]);
	return 0;
}