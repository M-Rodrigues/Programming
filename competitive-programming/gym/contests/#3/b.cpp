#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[4001],n,a,b,c;

int main() {
    scanf("%d%d%d%d",&n,&a,&b,&c);

    int sum=a+b+c;
    a=min(a,min(b,c));
    c=max(a,max(b,c));
    b=sum-a-c;

    for(int i=0;i<=n;i++) {
        if(i==a || i==b || i==c) dp[i]=1;

        if(i<max(a,max(b,c))) {
            int cont=0;

            if(i-a>0 && dp[i-a]!=0){
                dp[i]=max(dp[i],dp[i-a])+1;
                cont++;
            }

            if(i-b>0 && dp[i-b]!=0){
                dp[i]=max(dp[i],dp[i-b])+1;
                cont++;
            }

            if(i-c>0 && dp[i-c]!=0){
                dp[i]=max(dp[i],dp[i-c])+1;
                cont++;
            }

            if(cont>0) dp[i]-=(cont-1);
        } else {
            if(dp[i-a]!=0 || dp[i-b]!=0 || dp[i-c]!=0) dp[i]=max(dp[i-a],max(dp[i-b],dp[i-c]))+1;
        }
        //printf("dp[%d] = %d\n",i,dp[i]);
    }
    printf("%d\n",dp[n]);
    return 0;
}
