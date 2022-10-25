#include<stdio.h>
void f(int n){
    if(n){
        int *t=&n;
        f(n-1);
        printf("%d\n",n);
    }
    return;
}
int main(){
    int n;
    scanf("%d",&n);
    f(n);
    return 0;
}