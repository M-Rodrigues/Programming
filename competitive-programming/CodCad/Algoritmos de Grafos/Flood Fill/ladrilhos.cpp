#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define TAM 4000

int h, l, m[TAM][TAM], max_cor=0, res;
map< int, vector<int> > aresta;
map< int, int> comp, cor;

void dfs(int x){
    comp[x]=1;
    for (int i = 0 ; i < aresta[x].size() ; i++){
        int v = aresta[x][i];
        if ( comp[v] == -1 ) {
            comp[v]+=comp[x];
            dfs(v);
        }
        comp[x]++;
    }
}

// void mostrar_ladrilhos() {
//     for(int i =0; i<h;i++){
//         for(int j=0;j<l;j++){
//             printf("%d ",cor[i*l+j]);
//         }
//         printf("\n");
//     }
// }

void connect(int a, int b) { aresta[a].push_back(b); aresta[b].push_back(a); }

void fazer_conexoes(int i, int j) {
    int pos = i*l+j;
    if ( cor[pos] != 0 ) {
        if ( i == 0 && j > 0){
            if ( cor[pos]==cor[pos-1] )  connect(pos,pos-1);
        } else if ( i > 0 && j == 0){
            if ( cor[pos]==cor[pos-l] )  connect(pos,pos-l);
        }  else if ( i > 0 && j > 0 ){
            if ( cor[pos]==cor[pos-1] )  connect(pos,pos-1);
            if ( cor[pos]==cor[pos-l] )  connect(pos,pos-l);
        }
    }
}

void desfazer_conexoes() {
    for (int x = 0 ; x < h*l ; x++) {
        aresta[x].clear();
    }
}

// void mostrar_conexoes() {
//     for(int x = 0 ; x < h*l ; x++ ){
//         printf("%d (cor = %d )-> ",x,cor[x]);
//         for(int i=0;i<aresta[x].size();i++) printf("%d ",aresta[x][i]);
//         printf("\n");
//     }
// }

int main() {
    scanf("%d%d",&h,&l);

    res = l*h;

    for ( int i = 1 ; i <= h*l ; i++) comp[i] = -1;

    for ( int i = 0 ; i < h ; i++) {
        for ( int j = 0 ; j < l ; j++) {
            scanf("%d",&m[i][j]);
            int pos = i*l+j; 
            cor[pos] = m[i][j];

            if(cor[pos]>max_cor) max_cor = cor[pos];
        }
    }
    
    // Para todas as cores (1 a max_cor) calcular o menor conjunto existente

    for ( int k = 1 ; k <= max_cor ; k++ ) {
        // Pintar os buracos com a nova cor
        for ( int i = 0 ; i < h ; i++ ) {
            for ( int j = 0 ; j < l ; j++ ) {
                if ( m[i][j] == 0 ) cor[i*l+j]=k;
                // Fazer as conexões
                fazer_conexoes(i,j);
            }
        }

        // Calcular o menor conjunto
        for ( int i = 1 ; i <= h*l ; i++) comp[i] = -1;

        int menor = l*h;
        for (int x = 0 ; x < h*l ; x++) {
            if(cor[x]!=0 && comp[x]==-1) {
                dfs(x);
                if ( comp[x] < menor ) menor = comp[x];
            }
        }

        // Atualizar a cor do menor conjunto
        if ( res > menor ) res = menor;

        // Retirar a cor antiga dos buracos (nao eh preciso pois apenas sobreponho a cor)

        // Desconectar todas as arestas conectadas anteriormente
        desfazer_conexoes();
    }

    printf("%d\n",res);
    
    return 0;
}