#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    int n, m;

    scanf("%d%d",&n,&m);

    int mt[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&mt[i][j]);
        }
    }

    // Fazer o crivo;
    int tam=1000000, isPrime[tam]={};

    for(int i=2;i<tam;i++){
        if(isPrime[i]==0){
            for(int j=2*i;j<tam;j+=i){
                isPrime[j]=1; // nao eh primo
            }
        }
    }
    isPrime[1]=isPrime[0]=1;

    // Verificar linhas
    bool hasRow = false;
    for(int i=0;i<n;i++){
        int cont=0;
        //printf("\nLinha %d\n",i);
        for(int j=0;j<m;j++){
            //printf("%d %s eh primo\n",mt[i][j],!isPrime[mt[i][j]]?"":"nao");
            if(!isPrime[mt[i][j]]) cont++;
        }
        if(cont==m) hasRow=true;
    }
    
    //printf("%s\n",hasRow?"TEM LINHA SO COM PRIMOS!":"NAO TEM LINHA...");
    
    // Verificar colunas

    bool hasCol = false;
    for(int j=0;j<m;j++){
        int cont=0;
        //printf("\nColuna %d\n",j);
        for(int i=0;i<n;i++){
            //printf("%d %s eh primo\n",mt[i][j],!isPrime[mt[i][j]]?"":"nao");
            if(!isPrime[mt[i][j]]) cont++;
        }
        if(cont==n) hasCol=true;
    }

    //printf("%s\n",hasCol?"TEM COLUNA SO COM PRIMOS!":"NAO TEM COLUNA...");

    if(hasRow || hasCol) printf("%d\n",0);
    else {
        int moves=1e6;
        // Percorrendo as linhas
        for(int i=0;i<n;i++){
            int cont=0;
            for(int j=0;j<m;j++){
                int num = mt[i][j];
                while(isPrime[num]) cont++, num++;
            }
            //printf("Na linha %d tive que somar %d vezes\n",i,cont);
            if(cont<moves) moves=cont;
        }
        
        // Percorrendo as colunas
        for(int j=0;j<m;j++){
            int cont=0;
            for(int i=0;i<n;i++){
                int num = mt[i][j];
                while(isPrime[num]) cont++, num++;
            }
            //printf("Na coluna %d tive que somar %d vezes\n",j,cont);
            if(cont<moves) moves=cont;
        }

        printf("%d\n",moves);
    }

    return 0;
}
