#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n, maior, menor;
    scanf("%d",&n);
    vector<int> x(n);
    ll sum=0;

    for(int i=0;i<n;i++) {
        scanf("%d",&x[i]);
        sum+=x[i];

        if(i==0) maior=menor=x[i];
        else {
            if(x[i]>maior) maior=x[i];
            if(x[i]<menor) menor=x[i];
        }
    }

    //printf("menor = %d\tmaior = %d\n",menor,maior);

    if(maior==menor+1){
        int q_menor=0, q_maior=0;
        for(int i=0;i<n;i++)
            x[i]==menor ? q_menor++ : q_maior++;


        //printf("q_maior = %d\tq_menor = %d\n",q_maior,q_menor);

        printf("%d\n",n);
        for(int i=0;i<q_maior;i++)
            printf("%d ",maior);
        for(int i=0;i<q_menor;i++)
            printf("%d ",menor);
    } else {
        int meio=maior-1, q_meio=0, q_maior=0, q_menor=0;
        for(int i=0;i<n;i++)
            if(x[i]==menor) q_menor++;
            else if(x[i]==maior) q_maior++;
            else q_meio++;

        //printf("q_maior = %d\tq_meio = %d\tq_menor = %d\n",q_maior,q_meio,q_menor);


        if(sum==0) {
            printf("%d\n",q_meio);
            for(int i=0;i<n;i++) printf("%d ",meio);
        } else {
            int q1,q2,q3;

            q1=q_menor;
            q2=q_meio;
            q3=q_maior;

            if(q3>=q1){
                q3-=q1;
                q2+=2*q1;
                printf("%d\n",min(q2,q_meio)+min(q3,q_maior));
                for(int i=0;i<q2;i++) printf("%d ",meio);
                for(int i=0;i<q3;i++) printf("%d ",maior);
            } else {
                q1-=q3;
                q2+=2*q3;
                printf("%d\n",min(q2,q_meio)+min(q1,q_menor));
                for(int i=0;i<q2;i++) printf("%d ",meio);
                for(int i=0;i<q1;i++) printf("%d ",menor);
            }
        }
    }



    return 0;
}
