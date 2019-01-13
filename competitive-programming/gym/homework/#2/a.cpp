#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector< pair<int, int> > lap(n);

    for(int i=0;i<n;i++) scanf("%d%d",&lap[i].first,&lap[i].second);
    sort(lap.begin(),lap.end());
    bool res=false;
    for(int i=0;i<n-1;i++) if(lap[i].second > lap[i+1].second) res=true;
    printf("%s\n",(res?"Happy Alex":"Poor Alex"));

    return 0;
}
