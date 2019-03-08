#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, k_min, k_max;

ll comb(ll n, ll k){
    if(n<k) return 0;
    if(n==k) return 1;
    if(k==0) return n;
    return n*(n-1)/2;
}

int main() {

    scanf("%lld%lld",&n,&m);

    k_max=comb(n-m+1,2);
    k_min=n%m*comb(n/m+1,2)+(m-n%m)*comb(n/m,2);

    printf("%lld %lld\n",k_min,k_max);
    return 0;
}
