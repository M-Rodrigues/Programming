#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6+5;

int cmp[N];
vector<ll> p;
ll n, ans;

void primes() {
     for (ll i = 2; i*i < N; i++) if (!cmp[i]) {
        for (ll j = i*i; j < N; j+=i) cmp[j]=1;
    }
    for (ll i = 2; i < N; i++) if (!cmp[i]) p.push_back(i);
}

int main() {
    primes();

    while(scanf("%lld",&n)!=EOF){
        ans = n;
        
        //Calcular totiente(n) passando pelos seus fatores primos
        for (int i = 0; p[i]*p[i] <= n; i++) {
            if (n % p[i] == 0) {
                ans *= p[i]-1;
                ans /= p[i];
            }
            while (n % p[i] == 0) n /= p[i];
        }

        // para n grande, varemos até sua raiz, entao, se ainda sobrou alguma coisa eh pq ele eh primo
        if (n > 1) {
            ans *= n-1;
            ans /= n;
        }

        printf("%lld\n", ans/2);
    }
    return 0;
}