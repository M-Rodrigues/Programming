#include<bits/stdc++.h>
using namespace std;

char c;
int m, n, soma=0, k=1;

int main() {
    cin>>m;

    while(m!=0){
        cin>>n;
        soma=n;
        for(int i=0;i<m-1;i++){
            cin>>c;
            cin>>n;
            if(c=='+') soma+=n;
            if(c=='-') soma-=n;
        }
        cout<<"Teste "<<k<<endl;
        cout<<soma<<endl;
        k++;
        cin>>m;
    }


    return 0;
}
