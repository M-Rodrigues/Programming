#include <iostream>
#include<string>
using namespace std;

bool ehPrimo(unsigned long long int n) {
    if(n==2) return true;
    if(n==3) return true;
    if(n%2==0) return false;
    if(n%3==0) return false;

    unsigned long long int i, w;

    i = 5;
    w = 2;

    while (i*i <= n) {
        if (n%i==0) return false;
        i+=w;
        w=6-w;
    }
    return true;
}

int main () {
    unsigned long long int n, raiz;

    cin >> n;
    ehPrimo(n) ? cout << "sim" << endl : cout << "nao" << endl;

    return 0;
}


