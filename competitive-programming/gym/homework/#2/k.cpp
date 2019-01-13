#include<bits/stdc++.h>
using namespace std;

int v[2001]={};

int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int aux;
        scanf("%d",&aux);
        v[aux]++;
    }
    for(int i=0;i<2001;i++) if(v[i]!=0) printf("%d aparece %d vez(es)\n",i,v[i]);
    return 0;
}
