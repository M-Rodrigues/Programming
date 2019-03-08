#include <iostream>
#include<string>
using namespace std;

int main () {

    int n, a, b, teste=1;
    string jog_a, jog_b;

    cin >> n;
    while(n!=0) {

        cin >> jog_a;
        cin >> jog_b;
        cout << "Teste " << teste << endl;
        teste++;

        for(int i=0;i<n;i++){
            cin >> a >> b;
            ((a+b)%2==0) ? cout << jog_a << endl : cout << jog_b << endl;
        }

        cin >> n;
    }

    return 0;
}


