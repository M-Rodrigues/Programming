#include<iostream>
using namespace std;

int main() {

    char c;
    long int n, a, b, aux=0, result;

    cin >> n;
    cin >> a;
    cin >> c;
    if(c=='+') aux = 1;
    if(c=='*') aux = 2;

    cin >> b;


    if(c=='+') result = a+b;
    if(c=='*') result = a*b;

    result <= n ? cout << "OK" << endl : cout << "OVERFLOW" << endl;
}
