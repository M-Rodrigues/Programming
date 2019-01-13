#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, occ=0, t=1;
map< char, pair<int, int> > m;
vector<char> pass;
vector<int> v, sol;
set< vector<int> > s;


void checkVector() {
    int aux=s.count(v);
    if(aux==0){
        s.insert(v);
    } else {
        if(aux>occ) {
            sol.clear();
            for(int i=0;i<v.size();i++) sol.push_back(v[i]);
            occ=aux+1;
        }
    }
}

void makeVector(int i){
    if(i<6){
        v.push_back(m[pass[i]].first);
        makeVector(i+1);
        v.pop_back();
        v.push_back(m[pass[i]].second);
        makeVector(i+1);
        v.pop_back();
    } else {
        checkVector();
    }
}

int main() {
    while(scanf("%d",&n), n!=0){
        while(n--){
            //Lendo relações
            for(int i = 0;i<5;i++){
                int a, b;
                scanf("%d%d",&a,&b);
                m[(char)(i+'A')]=make_pair(a,b);
            }

            //Lendo senha digitada
            int cont=0;
            while(cont<6){
                char c;
                scanf("%c",&c);
                if(c>='A' && c<='E') pass.push_back(c), cont++;
                if(cont==6 && c==' ') scanf("%c",&c);
            }

            //for(auto itr=m.begin();itr!=m.end();++itr) printf("%c: (%d,%d)\n",itr->first,itr->second.first,itr->second.second);

            makeVector(0);
            pass.clear();

            v.clear();

        }
        //printf("\nTodas senhas testadas!! %d\n",occ);

        if(t!=1) printf("\n");
        printf("Teste %d \n",t);
        t++;
        for(int i=0; i<sol.size();i++) printf("%d ",sol[i]);
        printf("\n");
        sol.clear();
        occ=0;
    }
    return 0;
}
