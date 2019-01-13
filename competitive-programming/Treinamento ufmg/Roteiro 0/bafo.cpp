#include <iostream>
using namespace std;

int main () {

    int r, teste=1, a, b, tot_a, tot_b;

    cin >> r;
    while (r!=0) {
            tot_a=tot_b=0;
        for(int i=0;i<r;i++) {
            cin >> a >> b;
            tot_a+=a;
            tot_b+=b;
        }

        cout << "Teste " << teste << endl;
        teste++;
        (tot_a>tot_b) ? cout << "Aldo" << endl : cout << "Beto" << endl;

        cin >> r;
    }

    return 0;
}


