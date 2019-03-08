#include<bits/stdc++.h>
#include<string>
using namespace std;

int i, j, k, m, n, m1[100][100], m2[100][100], entradas[200][100], indc[100];

int main() {
    cin>>n;
    for(i=0;i<2*n;i++){
        for(j=0;j<n;j++){
            cin>>entradas[i][j];
        }
    }


    i=0;
    int cont=0;
    indc[0]=i;
    while(i<2*n){
        for(j=0;j<n;j++){
            bool target=false;
            for(k=i+1;k<n;k++){
                for(m=0;m<n;m++){
                    if(entradas[i][j]==entradas[k][m]) target=true;
                    if(target) break;
                }
                if(target) {
                    j=k-1;
                    i=j;
                    break;
                }
                if(!target) {
                    indc[cont]=k;
                    cont++;
                }
            }
        }
        i++;
    }

    cout<<"Indices"<<endl;
    for(i=0;i<n;i++) cout<<indc[i]<<" "<<endl;
}
