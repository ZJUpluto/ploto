#include<stdio.h> 
#include<stdlib.h> 
#define INF 0x3f3f3f3f
#define MAXN 103

int Graph[MAXN][MAXN],Earliest[MAXN],Lastest[MAXN];
int que[MAXN],in[MAXN],out[MAXN],max,N,M;


int GetEarliest();
void GetLastest();
void PrintRoute();

int main(){
	int i,n1,n2,weight;
	scanf("%d%d",&N,&M);
	for(i = 1; i <= M; i++){
		scanf("%d%d%d",&n1,&n2,&weight);
		Graph[n1][n2] = weight;
		out[n1]++;
		in[n2]++;
	}
	if(GetEarliest()){
		printf("%d\n",max);
		GetLastest();
		PrintRoute();
	}else{
		printf("0\n");
	}
	
}

int GetMin(int a,int b){
	return (a < b) ? a : b;
} 

int GetMax(int a,int b){
	return (a > b) ? a : b;
}

int GetEarliest(){
	int rear = 0,front = 0,i,v;
	for(i = 1; i <= N; i++)
		if(!in[i]) que[rear++] = i;
	while(front < rear){
		v = que[front++];
		max = GetMax(max,Earliest[v]);
		for(i = 1; i <= N; i++){
			if(Graph[v][i] != 0){
				Earliest[i] = GetMax(Earliest[i], Graph[v][i] + Earliest[v]);
				in[i]--;
				if(!in[i]) que[rear++] = i;
			}
		}
	}
	return rear == N;
}

void GetLastest(){
	int rear = 0,front = 0,i,v;
	for(i = 1; i <= N; i++){
		if(!out[i]) que[rear++] = i;
		Lastest[i] = max;
	}
		
	while(front < rear){
		v = que[front++];
		for(i = 1; i <= N; i++){
			if(Graph[i][v] != 0){
				Lastest[i] = GetMin(Lastest[i], Lastest[v] - Graph[i][v]);
				out[i]--;
				if(!out[i]) que[rear++] = i;
			}
		}
	}
}

void PrintRoute(){
	int i,j;
	for(i = 1; i <= N; i++){
		if(Earliest[i] != Lastest[i]) continue;
		for(j = N; j >= 1; j--){
			if(Graph[i][j] && Earliest[j] == Lastest[j] && Lastest[j] == Earliest[i] + Graph[i][j]) 
				printf("%d->%d\n",i,j);
		}
	}
}