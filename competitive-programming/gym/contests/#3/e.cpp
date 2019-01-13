#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main() {
    ll l, r;
    scanf("%lld%lld",&l,&r);

    if(l==r-1) printf("%d\n",-1);
    else {
        bool has=false;
        for(ll a=l; a<=r-2; a++){
            for(ll b=a+1; b<=r-1; b++) {
                for(ll c=b+1; c<=r; c++){
                    if(gcd(a,b)==1 && gcd(b,c)==1 && gcd(a,c)!=1) {
                        printf("%lld %lld %lld\n",a,b,c);
                        has=true;
                    }
                    if(has) break;
                }
                if(has) break;
            }
            if(has) break;
        }
        if(!has) printf("-1\n");
    }

    return 0;
}


