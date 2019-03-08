#include<bits/stdc++.h>
using namespace std;

int t, n, x, y;

bool cmp(pair<int ,int> a,pair<int ,int> b) { return (a.first<b.first) || ((a.first == b.first)&& (a.second > b.second)); }

int main() {
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        vector< pair<int, int> > v;
        scanf("%d",&n);
        for(int j=0;j<n;j++){
            scanf("%d%d",&x,&y);
            v.push_back(make_pair(x,y));
        }
        sort(v.begin(),v.end(), cmp);

        for(int j=0;j<n;j++){
            printf("%d %d\n",v[j].first, v[j].second);
        }

    }
}
