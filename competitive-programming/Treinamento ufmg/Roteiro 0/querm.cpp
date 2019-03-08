#include <iostream>
using namespace std;

int main() {

    int n, a[10000], win, cont=1;

    cin >> n;

    while(n!=0) {
        for(int i=0;i<n;i++){
            cin >> a[i];
            if((i+1)==a[i]) win = i+1;
        }

        cout << "Teste " << cont << endl;
        cout << win << endl;
        cont++;
        cout << endl;

        cin >> n;
    }

    return 0;
}
