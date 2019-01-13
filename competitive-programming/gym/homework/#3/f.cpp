#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll x, y, z, t;

ll fexp(ll a, ll b, ll mod){
    if(b==0) return 1;
    if(b%2==0) return fexp((a*a)%mod, b/2, mod)%mod;
    return ((a%mod)*fexp((a*a)%mod, b/2, mod))%mod;
}

int main() {

    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld%lld",&x,&y,&z);
        printf("%lld\n",fexp(x,y,z));
    }
    scanf("%lld",&t);
    return 0;
}
