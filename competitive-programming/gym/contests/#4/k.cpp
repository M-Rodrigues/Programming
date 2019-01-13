#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl
#define _ << " , " <<

typedef long long ll;
typedef long double ld;

const int N = 1e5+5;

int n, d, a, b;
vector<pair<int,int>> f;

int main() {
    scanf("%d%d",&n,&d);

    for (int i = 0 ; i < n ; i++) {
        scanf("%d%d",&a,&b);
        f.pb(mp(a,b));
    }

    sort(f.begin(),f.end());
    
    ll sum[n];

    sum[0] = f[0].nd;
    for (int i = 1; i < n; i++) sum[i] = f[i].nd + sum[i-1];
    //for (int i = 0; i < n; i++) printf("sum[%d] = %lld\n",i,sum[i]);

    //  Soma de todas as friendship entre i e j incluindo ambos -> sum[j] - sum[i] + f[i].nd;

    ll max_f = 0;

    for (int i = 0; i < n; i++) {
        
        //while (f[j].st - f[i].st >= d && i != j) j--;

        int l = i;
        int r = n - 1;
        //upper_bound
        while (l<r) {
            int md = (l+r)/2+1;
            if (f[md].st - f[i].st < d) l = md ;
            else r = md - 1;
        }

        //printf("começando em %d o melhor intervalo eh de (%d,%d)\n",i,i,r);

        ll res = sum[r] - sum[i] + f[i].nd;

        if (res > max_f) max_f = res;
    }
    
    printf("%lld\n",max_f);

    return 0;
}