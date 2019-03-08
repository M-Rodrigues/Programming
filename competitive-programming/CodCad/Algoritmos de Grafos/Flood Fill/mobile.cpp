#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
map< int, vector<int> > aresta;
map< int, int> comp;
bool bal = true;

void dfs(int x){
    if ( aresta[x].size() == 0 ) comp[x]=1;
    else {
        comp[x] = 0;
        for ( int i = 0 ; i < aresta[x].size() ; i++ ) {
            int v = aresta[x][i];
            if ( comp[v] == -1 ) dfs(v);
            comp[x] += comp[v];
        }
        comp[x]++; 
    }
}

void search() {
    for ( int x = 0 ; x <= n ; x++ ) {
        int tam = aresta[x].size(); 
        if ( tam != 0 && tam != 1 ) {
            int total;
            for ( int i = 0 ; i < tam ; i++ ) {
                int v = aresta[x][i];
                if ( i == 0 ) total = comp[v];
                else if ( comp[v] != total ) bal = false;
            }
        }
    }

}

int main() {
    scanf("%d",&n);
    for( int i = 0 ; i <= n ; i++ ) comp[i]=-1;

    for( int i = 0 ; i < n ; i++ ) {
        int a, b;
        scanf("%d%d",&a,&b);
        aresta[b].push_back(a); // a peça b tem a peça a pendurada nela 
    }

    dfs(0);
    search();
    
    printf("%s\n",bal?"bem":"mal");

    return 0;
}