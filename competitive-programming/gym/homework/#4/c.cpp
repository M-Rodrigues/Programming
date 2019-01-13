#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
int isPrime[10000000]={};
int tam = 10000000;

ll nextPrime(ll p){
    p++;
    while(isPrime[p] || n%p!=0) p++;
    return p;
}

int main() {
    //Crivo
    for(int i=2;i<tam;i++){
        if(isPrime[i]==0){
            for(int j=2*i;j<tam;j+=i){
                isPrime[j]=1; // nao eh primo
            }
        }
    }
    isPrime[1]=isPrime[0]=1;

    while(scanf("%lld",&n), n!=0){
        ll p=nextPrime(1);
        ll q=nextPrime(p);
        ll r=nextPrime(q);
        printf("%lld = %lld x %lld x %lld\n",n,p,q,r);
    }
    return 0;
}