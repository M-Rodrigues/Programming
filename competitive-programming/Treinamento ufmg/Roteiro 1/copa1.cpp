#include<iostream>
using namespace std;

int jogos[15][2], path[15];

void printArray(int tam) {
    int i;
    for(i=0;i<tam;i++) cout << path[i] << " ";
    cout << endl;
}

int power(int a, int b){
    if (b==0) return 1;
    return a*power(a,b-1);
}

int vencedor(int n, int nivel) {
    if (nivel==0) return n;
    if(jogos[n+15][0]>jogos[n+15][1]) return vencedor(n-power(2,nivel),nivel-1);
    else return vencedor(n+power(2,nivel),nivel-1);
}

int main() {

    int i, j, win;

    //Entrada dos jogos das oitavas
    for(i=0;i<8;i++) for(j=0;j<2;j++) cin>>jogos[i][j];

    for(i=0;i<8;i++) {
        if(jogos[i][0]>jogos[i][1]){
            path[i]=2*i;
        } else {
            path[i]=2*i+1;
        }
    }
    //printArray(8);

    //Entrada dos jogos das quartas
    for(i=0;i<4;i++) for(j=0;j<2;j++) cin>> jogos[i][j];

    for(i=0;i<4;i++) {
        if(jogos[i][0]>jogos[i][1]){
            path[i]=path[2*i];
        } else {
            path[i]=path[2*i+1];
        }
    }
    //printArray(4);

    //Entrada dos jogos das semis
    for(i=0;i<2;i++) for(j=0;j<2;j++) cin>> jogos[i][j];

    for(i=0;i<2;i++) {
        if(jogos[i][0]>jogos[i][1]){
            path[i]=path[2*i];
        } else {
            path[i]=path[2*i+1];
        }
    }
    //printArray(2);

    //Entrada do jogo da final
    for(i=0;i<1;i++) for(j=0;j<2;j++) cin>> jogos[i][j];

    for(i=0;i<1;i++) {
        if(jogos[i][0]>jogos[i][1]){
            path[i]=path[2*i];
        } else {
            path[i]=path[2*i+1];
        }
    }
    //printArray(1);

    cout << (char)((int)'A'+path[0]) << endl;

    return 0;
}
