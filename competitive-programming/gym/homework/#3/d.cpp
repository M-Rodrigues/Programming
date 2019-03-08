#include<bits/stdc++.h>
using namespace std;

vector<int> s;
int n, m;

int main() {
    scanf("%d",&n);
    scanf("%d",&m);

    for(int i=0;i<n;i++){
        int aux;
        scanf("%d",&aux);
        s.push_back(aux);
    }

    sort(s.begin(),s.end());

    int i=n-1, cont=0;
    bool has_solution = false;
    while(m>0 && i>=0){
        //printf("Tamanho restante: %d\nUSB (%d): %d\n\n",m,i,s[i]);
        m-=s[i];
        cont++;
        i--;
    }

    printf("%d\n",cont);



    return 0;
}

