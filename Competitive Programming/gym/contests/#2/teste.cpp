#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    int n;

    scanf("%d",&n);

    int crivo[n]={};

    for(int i=2;i<n;i++){
        if(crivo[i]==0){
            for(int j=2*i;j<n;j+=i){
                crivo[j]=1;
            }
        }
    }

    for(int i=0;i<n;i++) printf("%d ",crivo[i]);
}
