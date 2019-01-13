#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    scanf("%d%d",&n,&q);
    vector<int> v(n);
    for(int i=0;i<n;i++) scanf("%d",&v[i]);

    while(q--) {
        int key;
        scanf("%d",&key);
        int l=0, r=n-1;
        while(l<r){
            int m=(l+r)/2;
            if(v[m]<key) l=m+1;
            else r=m;
        }

        if(v[l]==key) printf("%d\n",l);
        else printf("%d\n",-1);
    }
    return 0;
}
