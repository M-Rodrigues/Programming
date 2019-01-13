#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, a, b;
map< int, vector<int> > aresta;
map< int, int> comp;

void dfs(int x){
    for (int i = 0 ; i < aresta[x].size() ; i++){
        int v = aresta[x][i];
        if ( comp[v] == -1 ) {
            comp[v] = comp[x];
            dfs(v);
        }
    }
}

int main() {
    scanf("%d%d",&n,&m);
    for ( int i = 1 ; i <= n ; i++ ) comp[i] = -1;
    
    for ( int i = 0 ; i < m ; i++ ){
        scanf("%d%d",&a,&b);
        aresta[a].push_back(b);
        aresta[b].push_back(a);
    }

    int times = 0;

    for( int i = 1 ; i <= n ; i++ ) {
        if ( comp[i] == -1 ) {
            times++;
            comp[i] = times;
            dfs(i);
        }
    }
    printf("%d\n",times);


    // for ( int x = 1 ; x <= n ; x++ ){
    //     printf("%d -> ",x);
    //     for ( int i = 0 ; i < aresta[x].size() ; i++ ) printf("%d ",aresta[x][i]);
    //     printf("\n");
    // }

    return 0;
}