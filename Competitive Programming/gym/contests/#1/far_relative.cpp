#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, a[5000], b[5000], i,j, total_m, total_f,max_f=0;
char sex[5000];
bool possible;

int main() {

    cin>>n;

    for(i=0;i<n;i++){
        cin>>sex[i];
        cin>>a[i]>>b[i];
//        cout<<sex[i]<<a[i]<<b[i]<<endl;
    }

    for(i=0;i<367;i++){
        total_m=total_f=0;
        for(j=0;j<n;j++){
            if(i>=a[j] && i<=b[j]){
                if(sex[j]=='F') total_f++;
                if(sex[j]=='M') total_m++;
            }
        }
        //cout<<((total_f>0&&total_m>0) ? "SIM " : "NAO ");
        //cout<<total_f<<" "<<total_m<<endl;
        if(max_f<min(total_f,total_m)) max_f=min(total_f,total_m);
    }

    cout<<2*max_f<<endl;

    return 0;
}

