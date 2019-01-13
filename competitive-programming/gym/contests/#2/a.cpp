#include<bits/stdc++.h>
using namespace std;

unsigned long long int n;

int main() {
    cin>>n;

    if(n%2==0) cout<<n/2<<endl;
    else cout<<"-"<<n/2 + 1<<endl;

    return 0;
}
