#include<bits/stdc++.h>
using namespace std;

int n;
map< set<int>, int > m;

int main() {
    scanf("%d",&n);

    while(n!=0){
        int maior=0;
        for(int i=0;i<n;i++){
            int aux;
            set<int> s;
            for(int j=0;j<5;j++) scanf("%d",&aux), s.insert(aux);
            m[s]++;
            if(m[s]>maior)maior=m[s];
        }

        int cont=0;
        auto itr = m.begin();
        for(int i=0;i<m.size();i++) {
            //cout<<itr->second<<" "<<endl;
            if(itr->second==maior){
                cont+=maior;
            }
            itr++;
        }

        printf("%d\n",cont);
        m.clear();
        scanf("%d",&n);
    }

    return 0;
}
