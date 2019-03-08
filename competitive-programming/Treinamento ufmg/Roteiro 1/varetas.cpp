#include<bits/stdc++.h>
using namespace std;

bool over=false;
int c, v, s, e, n, soma=0, k=1;

int main() {
    cin>>n>>c;
    for(int i=0;i<n;i++){
        cin>>s>>e;
        soma=soma-s+e;
        if(soma>c) over=true;
    }
    if(over) cout<<"S"<<endl;
    else cout<<"N"<<endl;
    return 0;
}
