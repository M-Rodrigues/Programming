#include<bits/stdc++.h>
using namespace std;

bool over=false;
int c, v, s, e, n, soma=0, k=1, i, cartas[5], val;

void printArray(int a[], int n) { for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl; }

bool isStraightFlush() {
    bool res=true;
    for(int i=0;i<4;i++){
        if(cartas[i]!=(cartas[i+1]-1)) res=false;
        if(!res) break;
    }
    return res;
}

bool isQuadra() {
    bool res=false;
    for(int i=0;i<5;i++){
        int cont=0;
        for(int j=i;j<5;j++){
            if(cartas[j]==cartas[i]) cont++;
        }
        if(cont==4) return true;
    }
    return res;
}

int findQuadra() {
    for(int i=0;i<5;i++){
        int cont=0;
        for(int j=0;j<5;j++){
            if(cartas[j]==cartas[i]) cont++;
        }
        if(cont==4) return cartas[i];
    }
}

int handValue(){
    if(isStraightFlush()) return cartas[0]+200;
    if(isQuadra()) return findQuadra()+180;
    if(isTrincaEPar()) return findTrinca()+160;
    if(isTrinca()) return findTrinca()+140;
    if(isDoisPar)
}

int main() {
    cin>>n;

    for(k=0;k<n;k++){
        for(i=0;i<5;i++) cin>>cartas[i];
        sort(cartas,cartas+5);
        printArray(cartas,5);
        val=handValue();
        cout<<"Pontuacao: "<<val<<endl;
    }





    return 0;
}
