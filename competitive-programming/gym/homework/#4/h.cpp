#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, q2,q3;

int gcd(int a, int b){
    if(a<0) a=-a;
    if(b<0) b=-b;
    if(a<b) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    scanf("%d",&n);
    if(n%2==1) n-=3, q3=1;
    q2=n/2;

    printf("%d\n",q2+q3);
    for(int i=0;i<q2;i++) printf("%d ",2);
    for(int i=0;i<q3;i++) printf("%d ",3);
    printf("\n");
    return 0;
}