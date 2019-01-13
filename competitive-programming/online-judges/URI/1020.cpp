#include<bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define _ << " , " << 
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin>>n;
    
    cout<<n/365<<" ano(s)\n";
    n%=365;
    cout<<n/30<<" mes(es)\n";
    n%=30;
    cout<<n<<" dias(s)";


    return 0;
}