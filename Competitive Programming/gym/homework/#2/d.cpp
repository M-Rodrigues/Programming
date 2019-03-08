#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, aux;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d%d",&n,&k);
        deque<int> d;
        for(int i=1; i<=n ;i++){
            scanf("%d",&aux);
            if(i<k) d.push_back(aux);
            else if(i==k) {
                d.push_back(aux);
                int maior = 0;
                for(int j=0;j<k;j++){
                    if(d[j]>maior) maior=d[j];
                }
                printf("%d ", maior);
            } else {
                d.erase(d.begin());
                d.push_back(aux);
                int maior = 0;
                for(int j=0;j<k;j++){
                    if(d[j]>maior) maior=d[j];
                }
                printf("%d ", maior);
            }
        }
        printf("\n");
    }

    return 0;
}
