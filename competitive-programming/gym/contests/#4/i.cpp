#include<bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define _ << " , " <<
using namespace std;
typedef long long ll;

const int N = 1e6+6;
ll n, x;
int cmp[N];
vector<ll> p;

void primes() {
    for (ll i = 2; i*i < N; i++) if (!cmp[i]) {
        for (ll j = i*i; j < N; j+=i) cmp[j]=1;
    }
    for (ll i = 2; i < N; i++) if (!cmp[i]) p.push_back(i);
}

int main() {
    primes();
    scanf("%lld",&n);
    while(n--){
        scanf("%lld",&x);
        bool has = false;

        if (x == 1) printf("NO\n");
        else {
            ll root = (ll)sqrt(x);
           
            if (!cmp[root]) if (x%root == 0 && root*root == x) has = true;

            printf("%s\n",has?"YES":"NO");
        }
    }
    return 0;
}