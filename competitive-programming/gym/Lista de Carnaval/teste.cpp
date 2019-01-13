#include<iostream>
using namespace std;

int main() {
    char c;

    cin>>c;

    if(c=='A') c = 'X';
    if(c=='B') cout<<"nao eh igual"<<endl;

    cout<<c<<endl;

    return 0;
}
