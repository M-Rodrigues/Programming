#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m, k, l, r, md;

// Usar PA para triangulo

ll soma_tri(ll h, ll l, ll r){
    ll sum = 0;
    sum += (2*h-r+1)*r/2;
    sum += (2*h-l+1)*l/2;
    return sum-h;
}

ll verifica(ll x){
    ll n_direita = min(n-k+1,x);
    ll n_esquerda = min(k,x);
    return soma_tri(x,n_esquerda,n_direita);
}

int main() {

    scanf("%lld%lld%lld",&n,&m,&k);

    l=1; r=m-n;


    if(n==1) printf("%lld",m);
    else {
        md=(l+r)/2;
        //printf("Teste inicial: md = %d\n",md);
        ll parcial = verifica(md);
        //printf("Soma neste caso: verifica(%d) = %d\n",md,parcial);
        while(l+1<r){
            md=(l+r)/2;
            parcial = verifica(md);
            //printf("l = %lld\tr = %lld\tmd = %lld\tverifica(%lld) = %lld\n",l,r,md,md,parcial);
            if(parcial>m-n) r=md;
            else l=md;
            //printf("Soma neste caso: verifica() = %d\n",parcial);
        }

        //printf("Alvo: %lld\n",m-n);
        //printf("l = %lld\t verifica(%lld) = %lld\n",l,l,verifica(l));
        //printf("r = %lld\t verifica(%lld) = %lld\n",r,r,verifica(r));
        //printf("md = %lld\t verifica(%lld) = %lld\n",md,md,verifica(md));

        if(verifica(r)<=(m-n)){
            if(verifica(r)>verifica(md)) printf("%lld\n",r+1);
            else printf("%lld\n",md+1);
        } else if(verifica(md)<=(m-n)){
            printf("%lld\n",md+1);
        } else {
            printf("%lld\n",l+1);
        }

        //printf("(l,%d) e (r,%d)\n",l,r);
        //printf("soma final: %d\n",verifica(md));
        //printf("%lld\n",md+1);
    }
    return 0;
}
