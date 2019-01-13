#include<bits/stdc++.h>
using namespace std;

int m[4][4], n, maior;
string s;

void showM(){
    printf("\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
}

bool isWall(int i, int j) { return m[i][j]==-1; }

bool lineOk(int row, int col) {
    //Caminhando para trás na linha
    for(int i=col-1;i>=0;i--){
        if(m[row][i]==-1) return true;
        if(m[row][i]==1) return false;
    }
    return true;
}

bool columnOk(int row, int col) {
    //Caminhando para cima na linha
    for(int i=row-1;i>=0;i--){
        if(m[i][col]==-1) return true;
        if(m[i][col]==1) return false;
    }
    return true;
}
bool isLegalPosition(int row, int col) { return lineOk(row,col)&&columnOk(row,col); }

int countRooks() {
    //showM();
    int total = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(m[i][j]==1) total++;
        }
    }

    if(total>maior) maior = total;
}

void solve(int row, int col){
    //  Estou fora do tabuleiro pela direita ? (significa q já percorri a ultima casa da coluna anterior e estou na primeira posicao da coluna fora do mapa)
    //      Conta qnts torre foram colocada -> Retorna a ultima linha da coluna anterior
    //      :   Programa segue

    //  Estou fora do tabuleiro por baixo ?
    //      Pule para primeira linha da proxima coluna -> (0,col+1)
    //      :   Programa segue


    // Se chegou até aqui é pq estou dentro do tabuleiro ainda, e estou na posição (row,col)
    //  É parede ?
    //      Pule para posição debaixo -> (row+1,col)
    //      :   É uma legal position ?
    //              Coloca uma torre e pula pra próxima posição -> (row+1,col)
    //          "Retira a coluna da posição (row,col)" e pula pra proxima posicao -> (row+1,col)

    if(col==n) {
        countRooks();
    } else if(row==n) {
        solve(0,col+1);
    } else {
        if(isWall(row,col)) solve(row+1,col);
        else {
            if(isLegalPosition(row,col)) {
                m[row][col] = 1;
                solve(row+1,col);
            }
            m[row][col] = 0;
            solve(row+1,col);
        }
    }
}

int main() {
    while(scanf("%d",&n), n!=0){

        //Leitura do tabuleiro
        for(int i=0;i<n;i++){
            cin>>s;
            //cout<<s<<"|"<<endl;
            for(int j=0;j<n;j++){
                if(s[j]=='.') m[i][j]=0;
                if(s[j]=='X') m[i][j]=-1;
            }
        }
        maior=0;
        //showM();
        solve(0,0);

        printf("%d\n",maior);

        //Limpando tabuleiro
        for(int i=0;i<4;i++) for(int j=0;j<4;j++) m[i][j]=0;
    }
    return 0;
}
