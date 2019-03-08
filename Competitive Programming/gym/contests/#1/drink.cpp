#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, v[100001]={}, i, q, j, cont, m, aux;

void printArray() { for(int i=0;i<13;i++) printf("%d ",v[i]); cout<<endl; }


int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&aux);
        v[aux]++;
    }
    //printArray();
    scanf("%d",&q);
    for(int i=1;i<100001;i++) v[i]+=v[i-1];
    //printArray();
    for(int i=0;i<q;i++){
        scanf("%d",&m);
        (m<=100000) ? printf("%d\n",v[m]) : printf("%d\n",n);
    }

    return 0;
}
