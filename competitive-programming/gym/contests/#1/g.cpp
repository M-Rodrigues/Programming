#include<bits/stdc++.h>
using namespace std;

string p, t;
vector<int> perm;
int md;

bool inPermutation(int i, int x){ // t[i] até o perm[x]
    for(int j=0;j<=x;j++) if(i==perm[j]) return true;
    return false;
}

bool check(int x){ //Vendo se é possível nasty apagar até a letra da x'ésima permutação
    string s;
    for(int i=0;i<t.size();i++){
        //printf("s.size() = %d\n",s.size());
        if(s.size()!=0) printf("s = %s\n",s.c_str());
        //printf("t[%d] = %c\n",i,t[i]);
        if(!inPermutation(i,x)){
            s.push_back(t[i]);
        }
    }
    //Procurar substring p;
    if(s.size()<p.size()) return false;
    else {
        bool hasSub = false;
        for(int i=0;i<(s.size()-p.size());i++){ // Fazer a busca por substring intervalada
            int cont=0;
            for(int j=0;j<p.size();j++){
                if(s[i+j]==p[j]) cont++;
            }
            if(cont==p.size()) hasSub=true;
        }

        if(hasSub) return true;
        else return false;
    }
}

int main() {
    cin>>t;
    cin>>p;
    for(int i=0;i<t.size();i++){
        int aux;
        scanf("%d",&aux);
        aux--;
        perm.push_back(aux);
    }

    int lo=0, hi=perm.size()-1;


    while(lo<hi){
        md=(lo+hi)/2;
        printf("Testando na posicao %d: (%d,%d)\n",md,lo,hi);
        if(check(md)) lo=md+1;
        else hi=md;
    }

    printf("%d\n",md+1);
    return 0;
}
