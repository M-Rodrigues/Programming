#include<iostream>
using namespace std;

int main() {

    int n, m, i, j, a[100][100], soma=0, max_soma=0;

    cin>>n>>m;

    for(i=0;i<n;i++){
        soma=0;
        for(j=0;j<m;j++){
            cin>>a[i][j];
            soma+=a[i][j];
        }
        if(soma>=max_soma) max_soma=soma;
    }

    //Percorrer as colunas;
    for(j=0;j<m;j++){
        soma=0;
        for(i=0;i<n;i++){
            soma+=a[i][j];
        }
        if(soma>=max_soma) max_soma=soma;
    }

    cout << max_soma << endl;

    return 0;
}
