#include <iostream>
#include <string>
using namespace std;

bool isPrime(unsigned int n) {
    if(n==2) return true;
    if(n==3) return true;
    if(n%2==0) return false;
    if(n%3==0) return false;

    unsigned int i, w;

    i = 5;
    w = 2;

    while (i*i <= n) {
        if (n%i==0) return false;
        i+=w;
        w=6-w;
    }
    return true;
}

int main() {

    string str;
    unsigned int num=0, i;

    while(getline(cin, str)){
        num = 0;

        for(i=0;i<str.size();i++) {
            if(str[i]>='a'&&str[i]<='z') num += (int)(str[i]-'a')+1;
            if(str[i]>='A'&&str[i]<='Z') num += (int)(str[i]-'A')+27;
        }

        if(isPrime(num)) cout << "It is a prime word." << endl;
        else cout << "It is not a prime word." << endl;
    }
    return 0;
}
