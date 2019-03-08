#include <iostream>
using namespace std;

unsigned long long int fat (int n) {
    if (n==0) return 1;
    return n*fat(n-1);
}

int main () {
    int n, m;

    while(cin >> m >> n) cout << fat(n) + fat(m) << endl;

    return 0;

}


