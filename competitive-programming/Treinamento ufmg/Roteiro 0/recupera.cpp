#include<iostream>
using namespace std;

int a[100];

int main() {

    bool nao_achei=true;
    int n, k=1,i, soma;

    while(cin >> n) {
        for(int i=0;i<n;i++) cin >> a[i];

        i=0;
        nao_achei = true;
        for(i=0;i<n;i++) {
            if(i==0 && a[i]==0){
                nao_achei = false;
            }
            else {
                soma=0;
                for(int j=i-1;j>=0;j--) soma+=a[j];
                if(soma==a[i]) {
                    nao_achei=false;
                }
            }
            if(nao_achei == false) break;
        }


        cout << "Instancia " << k << endl;
        if(nao_achei) cout << "nao achei" << endl;
        else cout << a[i] << endl;
        cout << "" << endl;
        k++;
    }
}

