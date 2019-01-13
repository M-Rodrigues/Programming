#include<bits/stdc++.h>
using namespace std;



int main() {

    int n, a, b, fa=0, fb=0;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&a);
        fa|=a;
    }

    for(int i=0;i<n;i++){
        scanf("%d",&b);
        fb|=b;
    }

    printf("%d\n",fa+fb);
    return 0;
}
