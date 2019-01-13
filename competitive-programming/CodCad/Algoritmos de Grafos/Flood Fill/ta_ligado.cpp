#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, a,b,op;
set< set<int> > v;

int main(){
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d%d",&op,&a,&b);
        set<int> s;
        s.insert(a);
        s.insert(b);

        if(op==0){
            printf("%d\n",(v.find(s)!=v.end())?1:0);
        } else {
            v.insert(s);
        }
        s.clear();
    }    
    v.clear();
    return 0;
}