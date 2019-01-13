#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define TAM 1050

vector<int> vizinhos[TAM];
int componente[TAM], inicio, fim, mapa[TAM][TAM],n,m;

void dfs(int x){
    for(int i=0;i<vizinhos[x].size();i++){
        int v = vizinhos[x][i];
        if(componente[v]==-1){
            componente[v]=componente[x]+1;
            dfs(v);
        }
    }
}

int main() {
    for(int i=0; i<TAM; i++) componente[i]=-1;

    scanf("%d%d",&n,&m);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){ // vertice i*m+j
            scanf("%d",&mapa[i][j]);
            int pos = i*m+j;

            if(mapa[i][j]==2) inicio = pos;
            if(mapa[i][j]==3) fim = pos;

            // montar ligações
            if(mapa[i][j]!=0) {
                if(i==0 && j>0){
                    if(mapa[i][j-1]!=0) 
                        vizinhos[pos].push_back(pos-1),  
                        vizinhos[pos-1].push_back(pos);  
                }
                if(i>0 && j>0){
                    if(mapa[i][j-1]!=0) 
                        vizinhos[pos].push_back(pos-1),  
                        vizinhos[pos-1].push_back(pos);
                    
                    if(mapa[i-1][j]!=0) 
                        vizinhos[pos].push_back(pos-m),  
                        vizinhos[pos-m].push_back(pos);
                }
            }
        }
    }

    // for (int x = 0; x <= n*m; x++) {
    //     printf("%d -> ",x);
    //     for (v : vizinhos[x]) printf("%d ",v);
    //     printf("\n");
    // }
    
    componente[inicio]=1;
    dfs(inicio);
    printf("%d\n",componente[fim]);

    return 0;
}