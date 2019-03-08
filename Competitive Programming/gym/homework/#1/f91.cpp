#include <iostream>
using namespace std;

typedef long long ll;

ll f(ll n){
    if(n<=100) return 91;
    if(n>=101) return n-10;
}

int main() {
    ll n;
    cin>>n;
    while(n!=0){
        cout<<"f91("<<n<<") = "<<f(n)<<endl;
        cin>>n;
    }
}

