#include<bits/stdc++.h>
using namespace std;

int n, m;
map<pair<int,int>,int> t;
int check[101];

int main() {
    scanf("%d%d",&n,&m);
    for(int k=0;k<m;k++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        t[make_pair(a,b)]=c;
    }



    //for(auto itr=t.begin();itr!=t.end();++itr) printf("Dupla (%d,%d) -> %d\n",itr->first.first,itr->first.second,itr->second);


    return 0;
}
