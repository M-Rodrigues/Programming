#include<bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define _ << " , " << 
using namespace std;
typedef long long ll;

int N, M, a, niv[100005], total[100005], max_niv=0, pres[100005];
vector<int> arestas[100005];

void mostrar_arestas() {
    for(int x=0; x<=N; x++){
        printf("%d -> ",x);
        for(int i = 0 ; i < arestas[x].size() ; i++) printf("%d ",arestas[x][i]);
        printf("\n");
    }
}

void mostrar_niveis() {
    for (int i = 0 ; i <= N ; i++) printf("%d -> %d\n",i,niv[i]);
}

void dfs(int x, int n) {
    if(n > max_niv) max_niv = n;
    total[n]++;
    niv[x] = n;    
    for(auto v : arestas[x]) dfs(v,n+1);
}

int main() {
    scanf("%d%d",&N,&M);

    for (int i = 1 ; i <= N ; i++) {
        scanf("%d",&a);
        arestas[a].push_back(i);
    }

    dfs(0,0);

    for (int i = 1 ; i <= M ; i++) {
        scanf("%d",&a);
        pres[niv[a]]++;
    }

    for (int i = 1 ; i <= max_niv ; i++) printf("%.2lf ",100*(double)(pres[i])/(double)(total[i]));
    printf("\n");

    return 0;
}