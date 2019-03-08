#include<bits/stdc++.h>
#include<string>
using namespace std;

typedef long long ll;

bool target;
int n, q, i, l, r, j, k, ans_i, ans_j, ans_k, p;
ll lis[300000], m;

ll maior(ll a, ll b){ return (a>b) ? a : b; }
ll maior3(ll a, ll b, ll c){ return maior(a,maior(b,c)); }

int main() {
    cin>>n>>q;

    for(i=0;i<n;i++) cin>>lis[i];

    for(p=0;p<q;p++){
        cin>>l>>r;
        l--;r--;
        target=false;
        for(i=l;i<=(r-2);i++){
            for(j=i+1;j<=(r-1);j++){
                for(k=j+1;k<=r;k++){
                    //cout<<"Comparando: "<<lis[i]<<lis[j]<<lis[k]<<endl;
                    m = maior3(lis[i],lis[j],lis[k]);
                    if(2*m<(lis[i]+lis[j]+lis[k])){
                        ans_i=i+1;
                        ans_j=j+1;
                        ans_k=k+1;
                        target=true;
                    }
                    //cout<<"Monto triangulo? "<<((target ? "SIM" : "NAO"))<<endl;
                    if(target) break;
                }
                if(target) break;
            }
            if(target) break;
        }
        if(target) cout<<ans_i<<" "<<ans_j<<" "<<ans_k<<endl;
        else cout<<"-1"<<endl;
    }

    return 0;
}
