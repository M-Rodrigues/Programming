#include <iostream>
using namespace std;

int main () {
    long long n, soma, aux, i;

    cin >> n;

    soma=0;
    for (i=0;i<n;i++) {
        cin >> aux;
        soma += aux;
    }

    cout << soma << endl;

    return 0;
}
