#include <iostream>
using namespace std;

int main () {

    int q, d, p, aux;


    cin >> q;
    while(q!=0) {
        cin >> d >> p;

        aux = p*q*d/(p-q);

        if(aux>1) cout << aux << " paginas" << endl;
        else cout << aux << " pagina" << endl;

        cin >> q;
    }
    return 0;
}
