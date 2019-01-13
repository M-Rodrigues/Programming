#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
int i, x, pos[3]={};

void printArray() { cout<<pos[0]<<" "<<pos[1]<<" "<<pos[2]<<endl; }

void swap(int a, int b){
    int aux;
    aux=pos[a];
    pos[a]=pos[b];
    pos[b]=aux;
}

void move_shell(ll n){
    if(n%2==0) swap(1,2);
    else swap(0,1);
}

int main() {

    cin>>n>>x;

    n%=5;
    pos[x]=1;
    //printArray();


    while(n>0){
        move_shell(n);
        //printArray();
        n--;
    }

    for(i=0;i<3;i++) if(pos[i]==1) cout<<i<<endl;

    return 0;
}
