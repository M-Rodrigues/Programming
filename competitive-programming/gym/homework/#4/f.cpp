#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

int main() {
    scanf("%d",&n);

    if(n==1 || n==2) printf("%d\n",-1);
    else if(n%2==1){
        ll l=n/2;
        printf("%lld %lld\n",(2*l*l+2*l+1),(2*l*l+2*l));
    } else if(n%4==2){
        ll l=n/4;
        printf("%lld %lld\n",(4*l*l+4*l+2),(4*l*l+4*l));
    } else {
        ll l=n/4;
        printf("%lld %lld\n",(4*l*l+1),(4*l*l-1));
    }

    return 0;
}
