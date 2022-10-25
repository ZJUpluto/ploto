#include<stdio.h>
#define max 100
#define Null -1

struct tree{
    char a;
    int l;
    int r;
}t1[max],t2[max];
int b[max];

int build(struct tree t[]){
    int i,n;
    char le,ri;
    scanf("%d\n",&n);
    if(n==0) return -1;
    for(i=0;i<n;i++) b[i]=0;
    for(i=0;i<n;i++){
        scanf("%c %c %c\n",&t[i].a,&le,&ri);
        if(le!='-'){
            t[i].l=le-'0';
            b[t[i].l]=1;
        }
        else t[i].l=-1;
        if(ri!='-'){
            t[i].r=ri-'0';
            b[t[i].r]=1;
        }
        else t[i].r=-1;
    }
    for(i=0;i<n;i++)  
        if(b[i]==0) break;
    return i;
}

int judge(int R1,int R2){
    if ((R1 == Null) && (R2 == Null))
		return 1;
	if (((R1 == Null) && (R2 != Null)) || ((R1 != Null) && (R2 == Null)))
		return 0;
	if (t1[R1].a != t2[R2].a)
		return 0;
	if ((t1[R1].l == Null) && (t2[R2].l == Null))
		return judge(t1[R1].r, t2[R2].r);
	if (((t1[R1].l != Null) && (t2[R2].l != Null)) &&
		((t1[t1[R1].l].a) == (t2[t2[R2].l].a)))
		return (judge(t1[R1].l, t2[R2].l) &&
			judge(t1[R1].r, t2[R2].r));
	else
		return (judge(t1[R1].l, t2[R2].r) &&
			judge(t1[R1].r, t2[R2].l));

}

int main(){
    int r1=build(t1);
    int r2=build(t2);
    if(judge(r1,r2)) printf("Yes\n");
    else printf("No\n");
    return 0;
}