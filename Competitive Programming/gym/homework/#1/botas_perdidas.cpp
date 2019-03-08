#include<iostream>
#include<string>
using namespace std;

int m[31][2];

void printMTX() {
    for(int i=0;i<31;i++){
        for(int j=0;j<2;j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

int menor(int a, int b) {
    if(a<b) return a;
    else return b;
}

int main() {

    int n;

    while(cin>>n){
        for(int i=0;i<n;i++){
            int tam; cin>>tam;
            char pe; cin>>pe;

            (pe=='D') ? m[tam-30][1]++ : m[tam-30][0]++;
        }
        //printMTX();

        int cont=0;
        for(int i=0;i<31;i++){
            if(m[i][0]!=0 && m[i][1]!=0) cont+=menor(m[i][0],m[i][1]);
            m[i][0]=m[i][1]=0;
        }
        cout<<cont<<endl;

    }


    return 0;
}

