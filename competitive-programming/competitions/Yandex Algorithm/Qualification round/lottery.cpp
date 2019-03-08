#include<bits/stdc++.h>
#include<string>
using namespace std;

int a[10], b[6], i, j, cont;

int main() {
    for(i=0;i<10;i++) cin>>a[i];
    int n; cin>>n;
    for(i=0;i<n;i++){
        cont=0;
        for(j=0;j<6;j++){
            int v; cin>>v;
            for(int k=0;k<10;k++){
                if(a[k]==v) cont++;
            }
        }

        if(cont>=3) cout<<"Lucky"<<endl;
        else cout<<"Unlucky"<<endl;
    }

}
