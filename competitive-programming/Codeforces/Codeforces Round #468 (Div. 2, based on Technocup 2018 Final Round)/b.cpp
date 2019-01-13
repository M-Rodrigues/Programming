#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,a,b,r=1;

void solve(int d) {
    if(d==1 && (a%2==1 && b%2==0)) printf("%d\n",r);
    else{
        b = (b%2==0) ? b/2 : b/2+1;
        a = (a%2==0) ? a/2 : a/2+1;
        r++;
        solve(b-a);
    }
}

int main() {
    scanf("%d%d%d",&n,&a,&b);
    if(a>b) swap(a,b);

    if(a<=n/2 && b>n/2) printf("Final!\n");
    else solve(b-a);
    return 0;
}
