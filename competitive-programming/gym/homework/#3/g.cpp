#include<bits/stdc++.h>
using namespace std;

int t,d,l,h,q,p;
char m[20];

int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d",&d);
        map<string, pair<int, int> > db;

        for(int i=0;i<d;i++){
            scanf("%s",m);
            scanf("%d%d",&l,&h);
            db[m]=make_pair(l,h);
        }

        scanf("%d",&q);

        for(int i=0;i<q;i++){
            scanf("%d",&p);

            auto itr = db.begin(), res=db.begin();
            int cont=0;

            while(itr!=db.end() && cont<2){
                if(itr->second.first<=p && itr->second.second>=p){
                    if(cont==0) res=itr, cont++;
                    else cont++;
                }
                itr++;
            }

            if(cont==1) printf("%s\n",res->first.c_str());
            else printf("UNDETERMINED\n");
        }
        if(t!=0) printf("\n");
        db.clear();
    }
    return 0;
}
