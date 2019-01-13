#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int t;
ll n;

bool isTidy(ll n) { // ex.: 123, 555, 2248
    if(n<10) return true;

    ll uni = n%10;
    n/=10;
    while(n!=0){
        if(uni < (n%10)) return false;
        uni = n%10;
        n/=10;
    }
    return true;
}

ll solve(ll x){
    while(!isTidy(x)) x--;
    return x;
}

int main() {
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%lld",&n);
        printf("Case #%d: %lld\n",i,solve(n));
    }
    return 0;
}
