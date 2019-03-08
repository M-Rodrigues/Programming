#include <iostream>
using namespace std;

int main() {

    int a,b,c;

    while(cin >> a >> b >> c){
        if(a+b+c==3 || a+b+c==0) cout << "*" << endl;
        else {
            if(a-b==a-c) cout << "A" << endl;
            if(b-a==b-c) cout << "B" << endl;
            if(c-a==c-b) cout << "C" << endl;
        }

    }
    return 0;
}

