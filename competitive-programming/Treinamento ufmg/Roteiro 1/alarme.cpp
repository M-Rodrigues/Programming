#include<bits/stdc++.h>
using namespace std;

int h1,h2,m1,m2,total;

int main() {
    cin>>h1>>m1>>h2>>m2;
    while(h1+h2+m1+m2!=0){
        total=0;

        if(m2<m1){
            h2--;
            m2+=60;
        }
        total=m2-m1;

        total+=(h2-h1)*60;
        if(total<0) total+=24*60;
        cout<<total<<endl;
        cin>>h1>>m1>>h2>>m2;
    }
    return 0;
}
