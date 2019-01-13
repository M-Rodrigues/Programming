#include <iostream>
using namespace std;

bool v[1001];

void all_false(int n) {
    int i;
    for(i=1;i<=n;i++) v[i]=false;
}

int main () {
    bool todos_salvos=true;
    int n, r, i, aux;

    while(cin >> n >> r) {
        all_false(n);
        todos_salvos = true;

        for(i=1;i<=r;i++) {
            cin >> aux;
            v[aux]=true;
        }

        for(i=1;i<=n;i++) {
            if(!v[i]){
                cout << i << " ";
                todos_salvos = false;
            }
        }

        if(todos_salvos) cout << "*" << endl;
        else cout << endl;

    }

    return 0;
}
