#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);

    map< pair<int, int>, string > m;

    for(int i=0;i<n;i++){
        int a, b;
        char c[20];
        string s;

        scanf("%d%d%s",&a,&b,c);
        s=c;
        m[make_pair(a,b)]=s;
    }

    int t;
    scanf("%d",&t);

    for(int i=0;i<t;i++){
        int a, b;
        scanf("%d%d",&a,&b);
        printf("%s\n",m[make_pair(a,b)].c_str());
    }

    return 0;
}
