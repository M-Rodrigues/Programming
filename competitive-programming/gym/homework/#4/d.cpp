#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> crivo(int M){
    vector<int> crivo(M)={};
    for(int i=2;i<M;i++){
        if(crivo[i]==0){
            for(int j=2*i;j<M;j+=i){
                crivo[j]=1;
            }
        }
    }
    return crivo;
}

int main(){
    int n,i;
    bool has=false;

    scanf("%d",&n);

    vector<int> p = crivo(n);

    for(i=2;i<p.size()/2;i++){
        if(p[i] && p[n-i]) has=true;
        if(has) break;
    }

    printf("%d %d\n",i,n-i);

    return 0;
}
