#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

double m, maior=0, menor=0, area;
ll n,a,i,t[100000], soma;

double area_corte(double low){
    double soma=0;
    for(int i=0;i<n;i++){
        if((double)t[i]>low) soma+=((double)t[i]-low);
    }
    return soma;
}

int main() {
    cin>>n>>a;
    while(n+a!=0){
        maior=menor=0;
        soma=0;
        for(i=0;i<n;i++){
            cin>>t[i];
            soma+=t[i];
            if(t[i]>(int)maior) maior=(double)t[i];
        }

        if(soma==a || a==0) cout<<":D"<<endl;
        else if(soma < a) cout<<"-.-"<<endl;
        else {
            m=(double)(maior+menor)/2;
            for(i=0;i<50;i++){
                area = area_corte(m);

                if(area-(double)a>1e-9){
                    menor=m;
                } else {
                    maior=m;
                }
                m=(double)(maior+menor)/2;
            }
            cout<<fixed;
            cout<<setprecision(4)<<m<<endl;
        }
        cin>>n>>a;
    }

    return 0;
}
