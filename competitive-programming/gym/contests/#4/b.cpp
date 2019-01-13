#include<bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define _ << " , " <<
using namespace std;
typedef long long ll;

ll t, n, m;
const int N = 32000;
int cmp[N];

vector<int> p_list;

void primes() {
    for (ll i = 2; i*i < N; i++) if (!cmp[i]) {
        for (ll j = i*i; j < N; j+=i) cmp[j]=1;
    }
    for (ll i = 2; i < N; i++) if (!cmp[i]) p_list.push_back(i);
}

int main() {
    //printf("%d\n",(int)sqrt(1e9));
    primes();
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&m,&n);
        
        set<int> list;
        for (int k = 0; k < p_list.size(); k++) {
            int begin;

            if (p_list[k] >= m) begin = p_list[k]*2;
            else begin = m + (p_list[k] - m%p_list[k])%p_list[k];

            for (int i = begin; i <= n; i+=p_list[k]) list.insert(i);
        }

        for (int i = m ; i <= n; i++) {
            if (i != 1) if (list.count(i)==0) printf("%d\n",i);
        }
        
        if(t!= 0) printf("\n");
    }    
    return 0;
}