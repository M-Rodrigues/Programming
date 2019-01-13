#include<iostream>
#include<string>
using namespace std;

unsigned long long mov=0;

void mover(string orig, string dest) {
    mov++;
}

void Hanoi(int n, string orig, string dest, string temp) {
    if(n==1) mover(orig,dest);
    else {
        Hanoi(n-1,orig,temp,dest);
        mover(orig,dest);
        Hanoi(n-1,temp,dest,orig);
    }
}

unsigned long long power(int a, unsigned long long b){
    if (b==0) return 1;
    return a*power(a,b-1);
}

int main() {
    unsigned long long n, cont=1;

    cin >> n;
    while(n!=0){

        mov = power(2,n)-1;
        cout<<"Teste "<<cont<<endl;
        cont++;
        cout<<mov<<endl;
        cout<<endl;

        cin >> n;
    }

    return 0;
}
