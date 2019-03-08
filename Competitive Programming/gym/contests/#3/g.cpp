#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int v, a[9];

int main() {
    scanf("%d",&v);

    for(int i=0;i<9;i++) scanf("%d",&a[i]);

    int menor=a[0], maior=0;

    for(int i=0;i<9;i++) if(a[i]<menor) menor=a[i], maior=i;


    int qtde = v/menor;

    if(qtde==0) printf("-1\n");
    else {
        for(int i=0;i<9;i++) if(a[i]==menor && i>maior) maior=i;

        for(int i=0;i<qtde;i++) printf("%d",maior+1);
        printf("\n");
    }
    return 0;
}


