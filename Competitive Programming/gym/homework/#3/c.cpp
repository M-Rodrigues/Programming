#include<bits/stdc++.h>
using namespace std;

int w[26]={}, k, maior=0;
string s;

int main() {
    cin>>s;
    scanf("%d",&k);

    for(int i=0;i<26;i++) {
        scanf("%d",&w[i]);
        if(maior<w[i]) maior=w[i];
    }

    int sum=0;
    for(int i=0;i<s.size();i++){
        sum+=w[(int)(s[i]-'a')]*(i+1);
    }

    for(int i=s.size()+1;i<=s.size()+k;i++){
        sum+=maior*i;
    }

    printf("%d\n",sum);
    return 0;
}
