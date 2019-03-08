#include<bits/stdc++.h>
using namespace std;

int n, t=1, num;
vector<int> v;

void db(char c){printf("\n(%c)\n",c);}

bool ehPrimo(int n) {
    if(n==2) return true;
    if(n==3) return true;
    if(n%2==0) return false;
    if(n%3==0) return false;

    unsigned long long int i, w;

    i = 5;
    w = 2;

    while (i*i <= n) {
        if (n%i==0) return false;
        i+=w;
        w=6-w;
    }
    return true;
}

int pickValidNumber(int res, int tam) { //Retorna o menor elemento n aparece na lista começando a procurar a partir do valor res || Retorna -1 se não exite tal número
    if(res==n) return -1;
    res++;
    while(res<=n){
        bool has=false;
        for(int i=0;i<=tam;i++){
            if(v[i]==res) has=true;
            if(has) break;
        }
        if(!has && res<=n) return res;
        res++;
    }
    if(res==n+1) return -1;
}

void solve(int i) {
    if(i==1){ //Condição de parada na volta
        //db('A');
        if(v[i]<=n){ //Retornando ao segundo da lista pq ñão existe mais solução com o valor que está em v[i]
            //db('B');
            num = pickValidNumber(v[i], i);
            if(num != -1) { //Existe ainda possibilidade de solucao
                //db('C');
                v[i]=num;
                //Check se eh primo
                if(ehPrimo(v[i]+v[i-1])) { /*db('D');*/ solve(i+1); }
                else { /*db('E');*/ solve(i); }
            } else { // Não existe mais solução possível (FIM DO PROGRAMA)
                //db('F');
                solve(-1);
            }
        } else { //v[i]>=n+1 (fora da condição do problema)
            //db('G');
            solve(-1);
        }
    } else if(i==n) { //Fora da lista, temos uma solução
        //db('H');
        //Checar circularidade
        if(ehPrimo(v[i-1]+v[0])){
            for(int i=0;i<n;i++) if(i<n-1) printf("%d ",v[i]); else printf("%d",v[i]);
            printf("\n");
            solve(i-1);
        } else {
            solve(i-1);
        }


    } else if(i>1) {
        //db('I');
        if(v[i]<=n){ // Primeira passagem nessa coluna;
            //db('J');
            num = pickValidNumber(v[i], i);
            if(num != -1){ //Existe ainda possibilidade de solução
                //db('K');
                v[i] = num;
                //Check se eh primo
                if(ehPrimo(v[i]+v[i-1])) {/*db('L')*/;solve(i+1);}
                else {/*db('M')*/;solve(i);}
            } else { //Voltar uma coluna;
                //db('O');
                v[i]=1;
                solve(i-1);
            }
        } else { //v[i]>=n+1 (fora da condição do problema)
            // Voltar para coluna anterior e fazer com q na proxima passagem o codigo tente resolver como se tivesse passando a primeira vez nessa coluna
            //db('P');
            v[i]=1;
            solve(i-1);
        }
    }

}

int main() {
    while(scanf("%d",&n)!=EOF) {
        for(int i=0;i<n;i++) v.push_back(1);
        if(t>1) printf("\n");
        printf("Case %d:\n",t);
        t++;
        solve(1);
        v.clear();
    }
    return 0;
}
