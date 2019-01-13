#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

string s1,s2;
ll n1, m1, n2, m2,x;

ll comb(ll n, ll k){
    if(k==0) return 1;
    if(k>n/2) return comb(n,n-k);
    return n*comb(n-1,k-1)/k;
}

ll fexp(ll a, ll b){ //Recursive
    if(b==0) return 1;
    if(b%2==0) return fexp(a*a,b/2);
    return a*fexp(a*a,b/2);
}

int main() {
    cin>>s1;
    cin>>s2;

    for(int i=0;i<s1.size();i++){
        if(s1[i]=='+') n1++;
        if(s1[i]=='-') m1++;
    }
    for(int i=0;i<s2.size();i++){
        if(s2[i]=='+') n2++;
        if(s2[i]=='-') m2++;
    }

    x=s2.size()-n2-m2;



    if(x+n2 < n1 || x+m2 < m1) printf("%.10Lf\n",(ld)0);
    else {
        
        double res = (double)comb(x,n1-n2)/(double)fexp(2,x);
        printf("%.10lf\n",res);
    }

    return 0;    
}
