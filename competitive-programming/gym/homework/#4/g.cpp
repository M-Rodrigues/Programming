#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k;

int main() {
    scanf("%d%d",&n,&k);
    int cont=0;
    vector<int> div;

    while(n > 1 && div.size()<k-1){
        int i=2;
        
        while(n%i!=0) i++;
        div.push_back(i);

        n/=i;
    }

    if(n!=1 && div.size()<k) div.push_back(n);

    if(div.size()<k || (div.size()<k && n==1)) printf("-1\n");
    else for(int i=0;i<div.size();i++) printf("%d ",div[i]);
}
