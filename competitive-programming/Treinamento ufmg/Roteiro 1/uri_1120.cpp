#include<iostream>
#include<string>
using namespace std;

int main() {

    int i, j;
    char d, aux[100];
    string n;


    cin >> d;
    cin >> n;

    while(d!='0' && n[0]!='0') {
        j=0;
        for(i=0;i<n.size();i++) {
            cout << n[i] << endl;
            if(n[i]!=d) {
                aux[j]=n[i];
                j++;
            }
        }
        cout << "Numero sem digito: " << aux << endl;

        cin >> d;
        cin >> n;
    }



    return 0;
}
