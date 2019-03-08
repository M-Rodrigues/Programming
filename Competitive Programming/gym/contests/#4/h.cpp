#include<bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define _ << " , " <<
using namespace std;
typedef long long ll;

const int N = 1e6+5;

ll k, w, n;

int main() {
    scanf("%lld%lld%lld",&k,&n,&w);
    ll ans = k*w*(w+1)/2-n;
    printf("%lld\n",(ans<0)?0:ans);
    return 0;
}