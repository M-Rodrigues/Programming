#include<bits/stdc++.h>
using namespace std;

char c;
int j,z , n, soma=0, k=1;

int main() {
    cin>>n;
    while(n!=0){
        soma=0;
        cout<<"Teste "<<k<<endl;
        for(int i=0;i<n;i++){
            cin>>j>>z;
            soma+=(j-z);
            cout<<soma<<endl;
        }
        cout<<""<<endl;
        k++;
        cin>>n;
    }

    return 0;
}
