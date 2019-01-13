#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, x, y, l=0, r=0;

int main() {
    cin>>n;
    while(n--){
        cin>>x>>y;
        (x>0) ? r++ : l++;
    }

    //cout<<l<<" : "<<r<<endl;

    if(r==0 || l==0) cout<<"YES"<<endl;
    else if(r==1) cout<<"YES"<<endl;
    else if(l==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}

