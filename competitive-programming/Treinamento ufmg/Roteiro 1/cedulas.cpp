#include<bits/stdc++.h>
using namespace std;

int n, qtde;

void contar(int x){
    qtde=n/x;
    cout<<qtde<<" nota(s) de R$"<<x<<",00"<<endl;
    if(n>=x) n=n-qtde*x;
    //cout<<"n("<<x<<") = "<<n<<endl;
}

int main() {
    cin>>n;
    cout<<n<<endl;

    contar(100);
    contar(50);
    contar(20);
    contar(10);
    contar(5);
    contar(2);
    contar(1);

    return 0;
}
