#include<bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;

int a,b,a1,b1;

int f(ll n){
    int cont=1;
    while(n!=1){
        if(n%2==1) n=3*n+1;
        else n=n/2;
        cont++;
    }
    return cont;
}

int main() {
    while(cin>>a>>b){
        if(a>b){
            a1=b;
            b1=a;
        } else {
            a1=a;
            b1=b;
        }
        int maior = 0;
        for(int i=a1;i<=b1;i++){
            int v = f(i);
            if(v > maior) maior = v;
        }
        cout<<a<<" "<<b<<" "<<maior<<endl;
    }
    return 0;
}

