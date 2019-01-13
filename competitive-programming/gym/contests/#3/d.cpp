#include<bits/stdc++.h>
using namespace std;

typedef long long ll;



int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int m, W;
        scanf("%d%d",&m,&W);
        vector<int> w(m);
        for(int i=0; i<m; i++) scanf("%d",&w[i]);

        sort(w.begin(),w.end());
        int cont=0, sum=0, i=0;

        while(i<m && sum<W){
            sum+=w[i];
            cont++;
            i++;
        }

        if(sum<=W) printf("%d\n",cont);
        else printf("%d\n",cont-1);

    }
    return 0;
}

