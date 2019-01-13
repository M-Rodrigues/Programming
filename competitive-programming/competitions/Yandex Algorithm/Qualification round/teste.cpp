#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, prices[100000], i, q, j, cont, money[100000];

int main() {

    cin>>n;

    for(i=0;i<n;i++) cin>>prices[i];
    cin>>q;
    for(i=0;i<q;i++) {
        cont=0;
        cin>>money[i];
        for(j=0;j<n;j++){
            if(money[i]>=prices[j]) cont++;
        }
        cout<<cont<<endl;
    }


    return 0;
}
