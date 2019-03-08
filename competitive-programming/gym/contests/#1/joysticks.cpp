#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int a1, a2, m[150][150]={};

int max_min(int a1, int a2){
    if(a1==0 || a2==0) return 0;
    if(a1==1) return (max_min(a1+1,a2-2)+1);
    if(a2==1) return (max_min(a1+-2,a2+1)+1);
    return (max(max_min(a1+1,a2-2),max_min(a1-2,a2+1))+1);
}

int main() {

    cin>>a1>>a2;
//    cout<<max_min(a1,a2)<<endl;

    int cont=0;

    while(a1>0 && a2>0){
        if(a1==1 && a2==1) break;

        cont++;
        if(a1>a2) swap(a1,a2);
        a1++;
        a2-=2;
    }

    cout<<cont<<endl;

    return 0;
}
