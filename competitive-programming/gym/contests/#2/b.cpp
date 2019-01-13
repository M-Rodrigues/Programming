#include<bits/stdc++.h>
using namespace std;

int n, t;
multiset<int> ms;

//Fast Median
//  Criar dois multisets e pegar o ultimo do primeiro multiset u e v
//      - Tirar o ultimo do u [auto it = u.end(), it--, it*]
//      - Retirar o primeiro do segundo e colocar no final do primeiro [u.insert(v.begin()), v.erase(v.begin())]
//
//  Colocar o iterador no início e ir movendo ele qnd adicionar um novo elemento.

void showMs(auto ptr){
    printf("Iterador na posicao: (%d , %d)\n",*ptr,ptr);
    for(auto itr = ms.begin() ; itr != ms.end() ; itr++){
        printf("(%d , %d) ",*itr, itr);
    }
    printf("\n");
}

int main() {
    scanf("%d",&t);
    auto it = ms.begin();
    //printf("Inicio: (%d , %d)\n",*it, it);
    while(t--){
        while(scanf("%d",&n) && n!=0){
            if(n!=-1){
                //Inserir
                if(ms.size()==0){
                    ms.insert(n);
                    it = ms.begin();
                } else if(ms.size()%2==0) {
                    ms.insert(n);
                    if(n>=*it) it++;
                } else {
                    ms.insert(n);
                    if(n<*it) it--;
                }
            } else {
                //Remover
                int res = *it;
                if(ms.size()==1){
                    ms.erase(it);
                    it=ms.begin();
                } else if(ms.size()%2==0){
                    auto aux = it;
                    aux--;
                    ms.erase(it);
                    it=aux;
                    it++;
                } else {
                    auto aux = it;
                    aux--;
                    ms.erase(it);
                    it=aux;
                }
                //printf("%d (%d)\n",res, it);
                printf("%d\n",res);
            }
            //showMs(it);
        }
        ms.clear();
    }
    return 0;
}

