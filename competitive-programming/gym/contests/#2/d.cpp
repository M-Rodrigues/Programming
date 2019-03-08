#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5+5;

int n;
ll sum, a[N], b[N], c[N], d[N];
vector<ll> s, t;

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld%lld%lld%lld",&a[i],&b[i],&c[i],&d[i]);
    }
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) s.push_back(a[i]+b[j]), t.push_back(c[i]+d[j]);
    sort(s.begin(),s.end());

    for(auto aux : t){
        auto r = upper_bound(s.begin(),s.end(),-aux);
        auto l = lower_bound(s.begin(),s.end(),-aux);
        sum += r-l;
    }
    printf("%lld\n",sum);
    return 0;
}
