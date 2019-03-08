#include<bits/stdc++.h>
using namespace std;

int n;

int main() {
    while(scanf("%d",&n), n!=0){
        vector<int> v(n);
        for(int i=0;i<n;i++) scanf("%d",&v[i]);
        sort(v.begin(),v.end());
        do{
            for(int i=0;i<n;i++) printf("%d ",v[i]);
            printf("\n");
        } while(next_permutation(v.begin(),v.end()));
        printf("\n");
        v.clear();
    }
    return 0;
}

