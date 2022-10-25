#include<stdio.h>
#include<stdlib.h>

void swap(int*a,int*b){
    int t=*a;*a=*b;*b=t;
}

void bubble_sort(int a[],int n){
    for(int i=n-1;i>0;i--){
        int flag=0;
        for(int j=0;j<i;j++){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
                flag=1;
            }
        }
        if(flag==0) break;
    }
}
void insert_sort(int a[],int n){
    for(int i=1;i<n;i++){
        int t=a[i];
        int j;
        for(j=i;j>0&&t<a[j-1];j--)
            a[j]=a[j-1];
        a[j]=t;
    }
}

void shell_sort(int a[],int n){
    int i,j,k,t,w;
    int shell[]={ 929, 505, 209, 109, 41, 19, 5, 1, 0 };
    for(i=0;shell[i]>=n;i++);
    for(j=shell[i];j>0;j=shell[++i])
    for(k=j;k<n;k++){
        t=a[k];
        for(w=k;w>=j&&a[w-j]>t;w-=j) a[w]=a[w-j];
        a[w]=t;
    }
}
void heap(int a[],int r,int n){
    int c,p,t;
    t=a[r];
    for(p=r;p*2+1<n;p=c){
        c=p*2+1;
        if(c!=n-1&&(a[c+1]>a[c]))
        c++;
        if(t>a[c]) break;
        else a[p]=a[c];
    }
    a[p]=t;

}
void heap_sort(int a[],int n){
    for(int i=n/2-1;i>=0;i--)
    heap(a,i,n);
    for(int i=n-1;i>=0;i--){
        swap(&a[i],&a[0]);
        heap(a,0,i);
    }
}
void merge(int a[],int t[],int l,int r,int end){
    int i=l;
    int num =end-l+1;
    int lend=r-1;
    while(l<=lend&&r<=end){
        if(a[l]<=a[r]) t[i++]=a[l++];
        else t[i++]=a[r++];
    }
    while(l<=lend) t[i++]=a[l++];
    while(r<=end) t[i++]=a[r++];
    for(int j=0;j<num;j++,end--)
    a[end]=t[end];
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                

void recursion(int a[],int t[],int l,int r){
    if(l<r){
        int c=(l+r)/2;
        recursion(a,t,l,c);
        recursion(a,t,c+1,r);
        merge(a,t,l,c+1,r);
    }
}
void merge_sort_recursion(int a[],int n){
    int *t;
    t=(int*)malloc(n*sizeof(int));
    recursion(a,t,0,n-1);
    free(t);
}
void unrecursion(int a[],int t[],int n,int len){
    int i;
    for(i=0;i<=n-2^len;i+=2*len)
        merge(a,t,i,i+len,i+2*len-1);
    if(i+len<n) merge(a,t,i,i+len,n-1);
    else for(int j=i;j<n;j++) t[j]=a[j];
}
merge_sort_unrecursion(a,n){
    int *t;
    t=(int*)malloc(n*sizeof(int));
    int len=1;
    while(len<n){
        unrecursion(a,t,n,len);
        len *=2;
        unrecursion(t,a,n,len);
        len *=2;
    }
    free(t);
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);

    //bubble_sort(a,n);
    //insert_sort(a,n);
    //shell_sort(a,n);
    //heap_sort(a,n);
    //merge_sort_recursion(a,n);
    //merge_sort_unrecursion(a,n);

    for(int i=0;i<n-1;i++)
    printf("%d ",a[i]);
    printf("%d",a[n-1]);
    return 0;

}