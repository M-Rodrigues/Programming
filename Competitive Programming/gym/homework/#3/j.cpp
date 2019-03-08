#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int m[9][9], colq, rowq, tam, k;

bool chk(int row, int col){
    if(row==0 || col==0) return false;
    if(row==9 || col==9) return false;
    // Mesma linha
    for(int i=col-1;i>=1;i--) if(m[row][i]==1) return false;
    //printf("Ninguem na mesma linha\n");

    // Mesma coluna
    for(int i=row-1;i>=1;i--) if(m[i][col]==1) return false;
    //printf("Ninguem na mesma coluna\n");

    // Diagonal superior
    for(int i=1; (col-i)>=1 && (row-i)>=1; i++) if(m[row-i][col-i]==1) return false;
    //printf("Ninguem na diagonal superior\n");

    // Diagonal inferior
    for(int i=1; (col-i)>=1 && (row+i)<=8; i++) if(m[row+i][col-i]==1) return false;
    //printf("Ninguem na diagoal inferior\n");

    return true;
}

void solve(int row, int col, int soln) {
    //printf("col %d\n",col);
    //showM();
    if(col==colq){
        if(m[rowq][colq]==0){
            m[rowq][colq]=1;

            for(int i=0;i<9;i++) m[0][i]=m[i][0]=0;
            if(chk(rowq,colq)){ //Verificando se pode colocar uma rainha nessa posição
                solve(1,col+1,soln);
            } else {
                m[rowq][colq]=0;
                solve(1,colq-1,soln);
            }
        } else {
            m[rowq][colq]=0;
            solve(1,col-1,soln);
        }
    } else if(col>8){ //Caiu fora do tabuleiro, então temos uma solução
        if(soln<=9) printf(" %d     ",soln);
        if(soln>=10) printf("%d     ",soln);
        soln++;
        for(int i=1;i<=8;i++) for(int j=0;j<=8;j++) if(m[j][i]==1) printf(" %d",j);
        printf("\n");
        solve(1,col-1,soln);
    } else if(col>=1 && col<=8) {
        if(row>8) { //Caiu pra fora do tabuleiro procurando uma posição possível
            solve(1,col-1,soln); // Volta para coluna anterior;
        } else {
            if(row==1){ //Voltando para coluna caso já tenha passado ou entrando pela primeira vez
                int i;
                for(i=1;i<=8;i++) if(m[i][col]==1) break;
                if(i>8) i=0;
                row=i+1;
                m[row-1][col]=0;
            }
            m[row][col]=1;
            //printf("(%d,%d)\n",row,col);
            //showM();

            for(int i=0;i<9;i++) m[0][i]=m[i][0]=0;

            if(chk(row,col)){ //Verificando se pode colocar uma rainha nessa posição
                solve(1,col+1,soln);
            } else {
                m[row][col]=0;
                solve(row+1,col,soln);
            }
        }
    } else if(col<1){

    }
}

int main() {
    scanf("%d",&tam);
    int n = tam;

    while(n--) {
        scanf("%d%d",&rowq,&colq);

        for(int i=0;i<=8;i++) for(int j=0;j<=8;j++) m[i][j]=0;

        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        solve(1,1,1);
        if(n!=0) printf("\n");
    }
    return 0;
}
