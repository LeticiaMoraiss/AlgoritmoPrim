#include<iostream>
using namespace std;

#define INF 9999
#define MAX 13

void Imprimir(int G[MAX][MAX], int n);
void Prim(int G[MAX][MAX], int n);

int main(){
	int G[MAX][MAX] = {
		{INF, 5, INF, INF, INF, INF, 1, 3, INF, INF, INF, INF, INF}, 
		{5, INF, 1, INF, INF, 4, 1, INF, INF, INF, INF, INF, INF}, 
		{INF, 1, INF, 7, INF, 2, INF, INF, INF, INF, INF, INF, INF}, 
		{INF, INF, 7, INF, 2, 6, INF, INF, INF, INF, INF, INF, INF}, 
		{INF, INF, INF, 2, INF, 7, INF, INF, INF, 3, INF, INF, INF}, 
		{INF, 4, 2, 6, 7, INF, 1, INF, 2, 3, INF, INF, INF}, 
		{1, 1, INF, INF, INF, 1, INF, 6, 5, INF, INF, INF, INF}, 
		{3, INF, INF, INF, INF, INF, 6, INF, 4, INF, 8, INF, INF}, 
		{INF, INF, INF, INF, INF, 2, 5, 4, INF, 8, 7, 4, INF}, 
		{INF, INF, INF, INF, 3, 3, INF, INF, 8, INF, INF, 3, 4}, 
		{INF, INF, INF, INF, INF, INF, INF, 8, 7, INF, INF, 2, INF}, 
		{INF, INF, INF, INF, INF, INF, INF, INF, 4, 3, 2, INF, 3}, 
		{INF, INF, INF, INF, INF, INF, INF, INF, INF, 4, INF, 3, INF} 
	};

	Imprimir(G, MAX);
	Prim(G, MAX);
	
	return 0;	
}

void Imprimir(int G[MAX][MAX], int n){
	
	cout<<"\n Grafo Original ";
	for(int i =0; i < n; i++){
	
		cout<<"\n";
		for(int j = 0; j < n; j++){
			
			if(G[i][j] == INF){
				cout<<"\tINF";
			}
			else{
				cout<<"\t"<<G[i][j];	
			}			
		}
	}
}

void Prim(int G[MAX][MAX], int n){
	
	int visitado[MAX];
	int src, dest;
	int total=0;
	int e = 0;
	
	for(int i=0; i<n; i++){
		visitado[i] = 0;
	}
		
	src = 0;	
	visitado[src] = 1;
     
    cout<<"\n\n Arvore geradora minima ";
	while(e < n - 1){
		
	 int min = INF;
	
		for(int i = 0; i < n; i++){
			
			if(visitado[i] == 1){
			
				for(int j = 0; j < n; j++){
			
					if(visitado[j] != 1){
			
						if(min > G[i][j] ){
			
							min = G[i][j];
							src = i;
							dest = j;
						}
					}
				}
			}
		}
		visitado[dest] = 1;
		total = total + G[src][dest]; //custo minimo		
		cout<<"\n( "<<src+1<<" , "<<dest+1<<" ) = "<<min;
		e++;
	}	
	cout<<"\n\n Custo minimo da arvore geradora: "<<total;
	
}
