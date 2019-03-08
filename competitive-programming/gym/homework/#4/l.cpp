#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t, n, m, x, y, MOD = 1e9+7;

ll fmexp(ll a, ll b, ll m){
    if(b==0) return 1;
    if(b%2==0) return fmexp((a*a)%m,b/2,m);
    return (a*fmexp((a*a)%m,b/2,m))%m;
}

ll modInv(ll a, ll m) { // Quando m é primo => Pequeno Teorema de Fermat
    return fmexp(a,m-2,m);
}

int main() {
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&m,&n);

        ll x,y;

        x = (((fmexp(m,n,MOD)-1)%MOD)*modInv(m-1,MOD))%MOD;
        y = fmexp(m,n,MOD);

        printf("%lld %lld\n",x,y);
    }
    return 0;
}
