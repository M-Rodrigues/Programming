#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m;

bool solve(int x){ // Diz se é possível resolver todas as provas até o dia x

}

int main() {
    scanf("%lld%lld",&n,&m);
    vector<ll> d(n), a(m);

    for(int i=0;i<n;i++) scanf("%lld",&d[i]); // prova q pode ser feita no dia d[i]
    for(int i=0;i<m;i++) scanf("%lld",&a[i]); // qnts dias de preparo para a prova i

    int l=1, r=n, md;

    while(l<r){
        md=(l+r)/2;
        if(solve(md)) r=md;
        else l=md+1;
    }

    if(solve(l)) printf("%d\n",l);
    else printf("-1\n");

    return 0;
}
