#include<iostream>
using namespace std;

int main() {

    int maior, pos, n;

    for(int i=1;i<=100;i++){
        cin >> n;
        if(i==1 || n > maior) {
            maior = n;
            pos = i;
        }
    }

    cout << maior << endl;
    cout << pos << endl;

    return 0;
}
