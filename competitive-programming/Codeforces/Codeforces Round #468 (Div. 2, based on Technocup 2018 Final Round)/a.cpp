#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int a,b;

ll f(int n){
    if(n==0) return 1;
    return f(n-1)+(n/2+1);
}

//  f(0)=1;
//  f(1)=1+1=2;
//  f(2)=2+2=4;
//  f(3)=4+2=6;
//  f(4)=6+3=9;
//  f(5)=9+3=12;

//  f(n)=f(n-1)+(n/2+1);


int main() {
    scanf("%d%d",&a,&b);
    if(a>b) swap(a,b);
    printf("%lld\n",f(b-a-1));
    return 0;
}
