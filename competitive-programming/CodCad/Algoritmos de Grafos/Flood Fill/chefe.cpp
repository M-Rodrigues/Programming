#include<bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define _ << " , " <<
using namespace std;
typedef long long ll;
 
int N, M, I, E, a, b;
int age[501], pos[501];
int vis[500];
vector<int> arestas[501];
 
void mostrar_grafo() {
  printf("GRAFO\n");
  for(int i=1; i<=N; i++){
    printf("%d -> ",i);
    for(auto v : arestas[i]) printf("%d ",v);
    printf("\n");
  }
}
void mostar_posicoes() {
  printf("POSICOES\n");
  for (int i = 1; i <= N; i++) printf("%d -> %d\n",i,pos[i]);
}
void mostar_ages() {
  printf("AGES\n");
  for (int i = 1; i <= N; i++) printf("%d -> %d\n",i,age[i]);
}
 
int dfs(int x){
  if(vis[x]) return vis[x];
  int min_x=age[x];
  for (auto v : arestas[x]){
    min_x=min(min_x,dfs(v));
  }
  return vis[x] = min_x;
}
 
void trocar(int a, int b){
  swap(pos[a],pos[b]);
  swap(age[pos[a]],age[pos[b]]);
}
 
int main() {
  char op;
  while(scanf("%d%d%d",&N,&M,&I)!=EOF){        
    for (int i = 1; i <= N; i++) {
      scanf("%d",&age[i]);
      pos[i]=i;
    }
 
    for (int i = 1; i <= M; i++) {
      int x, y;
      scanf("%d%d",&x,&y); // x gerencia y
      arestas[y].push_back(x);
    }
 
    //mostrar_grafo();
    //mostar_posicoes();
    //mostar_ages();
 
    for (int i = 1; i <= I; i++) {
      scanf("%d",&a);
      scanf("%c%d",&op,&a);
 
      if (op == 'T') {
        scanf("%d",&b);
        //printf("Trocar %d com %d\n",a,b);
        trocar(a,b);
      } else if (op == 'P') {
        E = a;
        //printf("Procurar gerente mais novo de %d\n",E);
 
        if(arestas[pos[E]].empty()) printf("*\n");
        else {
          for(int i = 0; i <= N; i++) vis[i] = 0;
          int min_x = 1e9;
          for (auto v : arestas[pos[E]]) min_x = min(min_x,dfs(v));
          //printf("Gerente mais novo de %d -> %d\n",E,min_x);
          printf("%d\n",min_x);
        }
      }
      //mostar_posicoes();
      //mostar_ages();
    }
 
    for (int x=1 ; x <= N; x++)
      arestas[x].clear();
  }
  return 0;
}