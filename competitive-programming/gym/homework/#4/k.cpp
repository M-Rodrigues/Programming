#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b,c,d,t;

ll gcd(ll a, ll b){
    if(a<0) a=-a;
    if(b<0) b=-b;
    if(a<b) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}

int main() {
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        printf("%lld\n",gcd(c-a,d-b)+1);
    }
    return 0;
}
