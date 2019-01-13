#include<bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define _ << " , " << 
using namespace std;
typedef long long ll;

int n;

int main() {
    scanf("%d",&n);

    int h,m,s;

    h = n/3600;
    n%=3600;
    m=n/60;
    n%=60;
    s=n;

    printf("%d:%d:%d\n",h,m,s);

    return 0;
}