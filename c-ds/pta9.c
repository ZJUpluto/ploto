#include<stdio.h>
#include<stdlib.h>

typedef struct treenode *tree;
struct treenode{
    int v;
    tree left,right;
    int flag;
};

tree newnode(int V){
    tree t=malloc(sizeof(struct treenode));
    t->v=V;
    t->left=t->right=NULL;
    t->flag=0;
    return t;
}

tree insert(tree t, int V){
    if(!t)  t=newnode(V);
    else if(V > t->v)
    t->right=insert(t->right,V);
    else
    t->left=insert(t->left,V);

    return t;
}

tree maketree(int N){
    tree t;
    int V;
    scanf("%d",&V);
    t=newnode(V);
    for(int i=1;i<N;i++){
        scanf("%d",&V);
        t=insert(t,V);
    }
    return t;
}

int check(tree t, int V){
    if(t->flag){
        if(t->v > V) return check(t->left,V);
        else if(t->v < V) return check(t->right,V);
        else return 0;
    }
    else{
        if(t->v == V){
            t->flag = 1;
            return 1;
        }
        else return 0;
    }
}

int judge(tree t,int N){
    int flag=0;//flag=0 nomal 
    int V;
    scanf("%d",&V);
    if(t->v != V) flag=1;
    else t->flag=1;
    for(int i=1;i<N;i++){
        scanf("%d", &V);
        if((!flag)&&(!check(t,V))) flag=1;
    }
    if(flag) return 0;
    else return 1;
}

void reset(tree t){
    if(t->left) reset(t->left);
    if(t->right) reset(t->right);
    t->flag = 0;  
}

void freetree(tree t){
    if(t->left) freetree(t->left);
    if(t->right) freetree(t->right);
    free(t);  
}


int main(void){
    tree t;
    int N,L;
    scanf("%d",&N);
    while(N){
        scanf("%d",&L);
        t = maketree(N);
        for(int i=0;i<L;i++){
            if(judge(t,N)) printf("Yes\n");
            else printf("No\n");
            reset(t); 
        }
        freetree(t);
        scanf("%d",&N);
    }
    return 0;
}

