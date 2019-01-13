#include <iostream>
using namespace std;

long long int fibo[45];

int main() {

    int n;

    cin >> n;

    if(n==1) cout << "0" << endl;
    if(n==2) cout << "0 1" << endl;
    if(n>=3) {
        fibo[0]=0;
        fibo[1]=1;
        cout << "0 1 ";
        for(int i=2;i<n;i++) {
            fibo[i]=fibo[i-1]+fibo[i-2];
            if(i==(n-1)) cout << fibo[i] << endl;
            else {
                cout << fibo[i] << " ";
            }
        }
    }


    return 0;
}
