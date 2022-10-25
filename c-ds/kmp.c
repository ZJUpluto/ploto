#include<stdio.h>
#include<string.h>
#define max 1000001
void buildmatch(char patt[],int match[],int m){
    int i,j;
    match[0]=-1;
    for(j=1;j<m;j++){
        i=match[j-1];
        while(i>=0&&patt[i+1]!=patt[j])
            i=match[i];
        if(patt[i+1]==patt[j])
            match[j]=i+1;
        else match[j]=-1;
    }
}
int KMP(char string[],char patt[]){
    int n=strlen(string);
    int m=strlen(patt);
    if(n<m) return -1;
    int s,p;
    int match[m];
    buildmatch(patt,match,m);
    s=p=0;
    while(s<n&&p<m){
        if(string[s]==patt[p]){
            s++;
            p++;
        }
        else if(p>0) p=match[p-1]+1;
        else s++;
    }
    return (p==m)?(s-m):-1;
    
}
int main(){
    char string[max];
    char patt[max];
    int n;
    scanf("%s",string);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",patt);
        int p=KMP(string,patt);
        if(p<0) printf("Not Found\n");
        else printf("%s\n",string+p);
    }
    return 0;
}