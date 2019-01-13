#include<bits/stdc++.h>
using namespace std;

int a[1000001]={}, n, index;

int main() {
    scanf("%d",&n);

    int pont=1;
    for(int i=0;i<n;i++){
        scanf("%d",&index);
        for(int j=pont;j<=pont+index;j++){
            a[j]=i+1;
        }
        pont+=index;
    }

    //for(int i=0;i<pont;i++) cout<<a[i]<<" ";

    int q;
    scanf("%d",&q);

    while(q--){
        int m;
        scanf("%d",&m);
        printf("%d\n",a[m]);
    }


    return 0;
}

