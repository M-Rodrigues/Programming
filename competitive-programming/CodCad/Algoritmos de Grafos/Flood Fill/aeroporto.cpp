#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int A,V,maior=0,aux;

int main(){
    int t=1;
    while(scanf("%d%d",&A,&V), A+V!=0){
        map<int,int> m;
        maior=0;
        for(int i=0;i<2*V;i++){
            scanf("%d",&aux);
            m[aux]++;
            if(m[aux]>maior) maior=m[aux];
        }

        //for(int i=1;i<=A;i++) printf("m[%d] = %d\n",i,m[i]);
        printf("Teste %d\n",t);
        t++;
        for(int i=1;i<=A;i++) if(m[i]==maior) printf("%d ",i);
        printf("\n\n");
        m.clear();
    }
    return 0;
}