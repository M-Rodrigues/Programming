#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPrime(int n) {
    if(n==2) return true;
    if(n==3) return true;
    if(n%2==0) return false;
    if(n%3==0) return false;

    int i, w;

    i = 5;
    w = 2;

    while (i*i <= n) {
        if (n%i==0) return false;
        i+=w;
        w=6-w;
    }
    return true;
}

int totient(int n) {
    int phi=n;
    for(int i=2; i<n; i++){
        if(isPrime(i) && n%i==0) phi=phi*(i-1)/i;
    }
    return phi;
}
int fat(int n) {
    if(n==0) return 1;
    int res=1;
    for(int i=1;i<=n;i++) res*=i;
    return res;
}
int main() {
    cout<<fat(7)<<endl;
    return 0;
}
