#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m, lig[1000][1000]={};
vector<string> mp;


int main(){
    scanf("%d%d",&m,&n);
    int lig[m][n], costa=0, total=0;
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        mp.push_back(s);
        for(int j=0;j<n;j++){
            lig[i][j]=0;
            //printf("Posicao (%d,%d) = %c ",i,j,mp[i][j]);
            if(mp[i][j]=='#') {
                total++;
                if(i==0 && j>0){
                    if(mp[i][j-1]=='#') lig[i][j]++, lig[i][j-1]++; 
                }
                if(i>0 && j>0){
                    if(mp[i][j-1]=='#') lig[i][j]++, lig[i][j-1]++; 
                    if(mp[i-1][j]=='#') lig[i][j]++, lig[i-1][j]++; 

                    if(lig[i][j]==4) costa++;
                    if(lig[i-1][j]==4) costa++;
                    if(lig[i][j-1]==4) costa++;
                }
            }  
        }
    }
    printf("%d\n",total-costa);

    return 0;
}