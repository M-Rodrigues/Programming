#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;

void printArray(int a[], int n) { for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl; }

void solve(ll n){
    ll a_lim, b_lim, c_lim, i, j, k, soma;
    bool has_solution=false;


    //cout<<"Testando "<<n<<endl;

    for(i=0;(i*1234567<=n);i++){
        for(j=0;(1234567*i + 123456*j <= n);j++){
            if((n-1234567*i-123456*j)%1234==0) has_solution=true;
            if(has_solution) break;
        }
        if(has_solution) break;
    }
    if(has_solution) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    cin>>n;
    solve(n);
    return 0;
}

