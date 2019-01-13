#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll m=1e9+7;

ll fmexp(ll a, ll b, ll m){ //Recursive
    if(b==0) return 1;
    if(b%2==0) return fmexp((a*a)%m,b/2,m);
    return (a*fmexp((a*a)%m,b/2,m))%m;
}


ll f(ll n){
    return (fmexp(2,n-1,m)*((fmexp(2,n,m)+1)%m))%m;
}


int main() {
    ll n;
    cin>>n;

    if(n==0) cout<<1<<endl;
    else cout<<f(n)<<endl;
    return 0;
}
