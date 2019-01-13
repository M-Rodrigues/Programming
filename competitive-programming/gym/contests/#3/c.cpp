#include<bits/stdc++.h>
using namespace std;

int state[9][9], m[9][9];
bool has;

void showM(){
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
}
void showState(){
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            printf("%d ",state[i][j]);
        }
        printf("\n");
    }
}

bool checkCol(int n, int j){
    for(int i=0;i<9;i++){
        if(m[i][j]==n) return false;
    }
    //printf("Coluna %d ainda nao tem o %d\n",j,n);
    return true;
}

bool checkRow(int n, int i){
    for(int j=0;j<9;j++){
        if(m[i][j]==n) return false;
    }
    //printf("Linha %d ainda nao tem o %d\n",i,n);
    return true;
}

bool checkSquare(int n, int row, int col){
    for(int i=(row/3*3);i<(row/3*3+3);i++){
        for(int j=(col/3*3);j<(col/3*3+3);j++){
            if(m[i][j]==n) return false;
        }
    }
    //printf("Quadrado (%d,%d) ainda nao tem o %d\n",row,col,n);
    return true;
}

bool checkPosition(int n, int i, int j){
    return checkCol(n,j)&&checkRow(n,i)&&checkSquare(n,i,j);
}

int getValidNum(int num, int j){
    for(int n=num+1;n<=9;n++){
        //printf("Procurando %d na coluna %d\n",n,j);
        int cont=0;
        for(int i=0;i<9;i++){
            if(m[i][j]!=n) cont++;
        }
        //printf("Contagem para %d = %d\n",n,cont);
        if(cont==9) return n;
    }
    return -1;
}

pair<int,int> last_position(int i, int j){
    i--;
    while(j>=0){
        while(i>=0){
            if(state[i][j]==-1) return make_pair(i,j);
            i--;
        }
        j--;
        i=8;
    }
    return make_pair(-1,-1);
}

void db(char c){ printf("(%c)\n",c); }

void solve(int i, int j){
    //printf("(%d,%d) = %d\n",i,j,m[i][j]);
    //showM();

    if(!has) {
        if(j==9){ //saí pela lateral, então tenho solução
            //db('A');
            showM();
            has=true;
            solve(0,j-1);
        } else if(i==9) { // saí por baixo, pular para coluna seguinte seguinte
            //db('B');
            solve(0,j+1);
        }else if(i<0) {
            //db('C');
            solve(0,j-1);
        } else if(j<0) { // voltei ao início, verificar se tem solução
            //db('D');
            if(!has) printf("No solution\n");
        } else {
            //db('E');
            if(state[i][j]==0) {
                //db('F');
                solve(i+1,j);
            } else {
                //db('G');
                int num = getValidNum(m[i][j],j); //Possível valor a ser testado;
                m[i][j]=0;
                while(num!=-1 && !checkPosition(num,i,j)) num=getValidNum(num,j);

                if(num==-1) {
                    //db('H');
                    m[i][j]=0;
                    solve(last_position(i,j).first,last_position(i,j).second);
                } else {
                    //db('I');
                    m[i][j]=num;
                    solve(i+1,j);
                }
            }
        }
    }
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                scanf("%d",&m[i][j]);
                if(m[i][j]==0) state[i][j]=-1;
                else state[i][j]=0;
            }
        }
        has = false;
        solve(0,0);

        //int i=1,j=0;
        //printf("Ultima posicao dado (%d,%d) = (%d,%d)\n",i,j,last_position(i,j).first,last_position(i,j).second);

    }

    return 0;
}
