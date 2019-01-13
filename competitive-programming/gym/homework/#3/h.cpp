#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, t, maior, sum_maior;


int main() {
    while(scanf("%d%d",&n,&t)!=EOF){
        vector< pair<int,int> > tr;
        for(int i=0;i<t;i++) {
            int aux;
            scanf("%d",&aux);
            tr.push_back(make_pair(i,aux));
        }
        map<int,vector< pair<int,int> > > m;
        vector<int> sum(n+1);
        for(int i=0;i<n;i++) sum[i]=0;

        sum_maior=maior=0;
        m[0]={};
        for(int i=0;i<=n;i++){
            //printf("sum[%d] = %d\n",i,sum[i]);
            for(int j=0;j<t;j++){
                //printf("Fita de %d min\n",tr[j]);
                // Verficar se i-tr[j]>=0
                if(i-tr[j].second>=0){
                    //printf("%d-tr[%d] = %d\n",i,j,i-tr[j]);
                    int x1=sum[i];
                    int x2=sum[i-tr[j].second]+tr[j].second;
                    //printf("(sum[%d],sum[%d-tr[%d]]+tr[%d]) = (%d,%d)\n",i,i,j,j,x1,x2);
                    if(x2<=n && x2>x1){
                        bool has = false;
                        for(int k=0;k<m[i-tr[j].second].size();k++) if(m[i-tr[j].second][k].second==tr[j].second) has = true;
                        if(!has){
                            sum[i]=x2;
                            //copiar vetor de m[i-tr[j]] para m[i]
                            m[i]=m[i-tr[j].second];
                            m[i].push_back(tr[j]);

                            if(sum[i]>sum_maior) maior=i, sum_maior=sum[i];
                        }
                    }
                }
            }

            sort(m[i].begin(),m[i].end());
        }

        for(int j=0;j<m[maior].size();j++) printf("%d ",m[maior][j].second);
        printf("sum:%d\n",sum[maior]);

        m.clear();
        tr.clear();
    }
    return 0;
}
