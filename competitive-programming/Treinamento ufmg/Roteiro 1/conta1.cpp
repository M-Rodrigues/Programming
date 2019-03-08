#include <iostream>
using namespace std;

int main() {

    int n, total=7;

    cin >> n;

    if(n>=100) {
        total+=5*(n-100);
        total+=160;
    } else if(n>=30) {
        total+=2*(n-30);
        total+=20;
    } else if(n>=10) {
        total+=(n-10);
    }

    cout << total << endl;

    return 0;
}
