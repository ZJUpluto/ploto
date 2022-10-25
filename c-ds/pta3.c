#include<stdio.h>
#include<stdlib.h>
struct polynode{
    int c;
    int e;
    struct polynode *link;
};
    typedef struct polynode *poly;

void attach(int c,int e,poly *rea){
    poly p;
    p=malloc(sizeof(struct polynode));
    p->c=c;
    p->e=e;
    p->link=NULL;
    (*rea)->link=p;
    *rea=p;

}

poly read(void){
    poly p,rear,t;
    int c,e,N;
    p=(poly)malloc(sizeof(struct polynode));
    //p->link=NULL;
    rear=p;
    scanf("%d",&N);
    while(N--){
        scanf("%d %d",&c,&e);
        attach(c,e,&rear);
    }    
    t=p;p=p->link;free(t);
    return p;
}

int compare(int a ,int b ){
if (a == b) return 0;
else if (a > b) return 1;
else return -1;
}

poly add(poly p1,poly p2){
    poly f,r,t;
    int sum;
    f=(poly)malloc(sizeof(struct polynode));
    r=f;
    while(p1&&p2)
        switch(compare(p1->e,p2->e)){
        case 1:
            attach(p1->c,p1->e,&r);
            p1 = p1->link;
            break;
        case -1:
            attach(p2->c,p2->e,&r);
            p2 = p2->link;
            break;
        case 0:
            sum = p1->c + p2->c;
            if(sum)
            attach(sum,p1->e,&r);
            p1=p1->link;
            p2=p2->link;
            break;
        }
    for( ;p1;p1=p1->link)attach(p1->c,p1->e,&r);
    for( ;p2;p2=p2->link)attach(p2->c,p2->e,&r);
    //r->link=NULL;
    t=f;
    f=f->link;
    free(t);
    return f;
}

void print(poly p){
    int flag =1;
    while(p){
        if(flag)
            flag=0;
        else
            printf(" ");
        printf("%d %d",p->c,p->e);
        p=p->link;
    }
    printf("\n");
}

int main(void){
    
    poly p1,p2,ps;
    p1=read();
    p2=read();
    ps=add(p1,p2);
    print(ps);

    return 0;
}