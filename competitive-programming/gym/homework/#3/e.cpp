#include<bits/stdc++.h>
using namespace std;

int n, a, b;
string s;

int main() {
    scanf("%d%d%d",&n,&a,&b);
    getline(cin, s);
    getline(cin, s);

    if(a>b) swap(a,b);
    a--; b--;

    //cout<<s<<endl;

    /*
    if(s[a]==s[b]) printf("%d\n",0);
    else {
        int i=b;
        while(i!=a && s[i]==s[b]) i--;
        int v1=b-i;

        i=a;
        while(i!=b && s[i]==s[a]) i++;
        int v2=i-a;

        printf("%d\n",min(v1,v2));
    }
    */

    if(s[a]==s[b]) printf("%d\n",0);
    else printf("%d\n",1);

    return 0;
}

