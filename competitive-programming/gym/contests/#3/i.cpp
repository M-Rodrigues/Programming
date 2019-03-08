#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int total=0,n;

int main() {
    scanf("%d",&n);

    map<string, int> m;

    while(n--){
        string s;
        cin>>s;
        m[s]++;

        total=max(m[s],total);
    }

    printf("%d\n",total);

    return 0;
}

