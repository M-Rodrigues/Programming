#include <iostream>
using namespace std;

typedef long long ll;

struct tempo {
    int h,m;

    tempo(int h, int m):h(h), m(m) {}

    int operator-(tempo t){
        int aux = (h-t.h)*60+(m-t.m);
        if(aux < 0) aux += 24*60;
        return aux;
    }
};

int main() {
    int h1,h2,m1,m2;
    cin>>h1>>m1>>h2>>m2;
    while(h1+h2+m1+m2!=0){
        tempo t1(h1,m1), t2(h2,m2);
        cout<<t2-t1<<endl;
        cin>>h1>>m1>>h2>>m2;
    }
}

