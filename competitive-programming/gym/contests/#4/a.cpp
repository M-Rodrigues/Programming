#include<bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define _ << " , " <<
using namespace std;
typedef long long ll;

ll n, m, inicio, steps=0;
ll vis[100][100];
int grid[100][100];

void solve(int i, int j) {
    steps++;
    if (i >= 0 && i < n && j >= 0 && j < m) {
        if (vis[i][j] != 0) printf("%lld step(s) before a loop of %lld step(s)\n",vis[i][j]-1,steps-vis[i][j]);
        else {
            vis[i][j] = steps;
            if (grid[i][j] == 1) solve(i-1,j);
            if (grid[i][j] == 2) solve(i,j+1);
            if (grid[i][j] == 3) solve(i+1,j);
            if (grid[i][j] == 4) solve(i,j-1);
        }
    } else {
        printf("%lld step(s) to exit\n",steps-1);
    }
}

int main() {
    while(scanf("%lld%lld%lld",&n,&m,&inicio), n+m+inicio!=0){
        inicio--;

        for (int i = 0; i < n ; i++){
            string s;
            cin>>s;
            for (int j = 0; j < m; j++) {
                
                if (s[j] == 'N') grid[i][j] = 1;
                if (s[j] == 'E') grid[i][j] = 2;
                if (s[j] == 'S') grid[i][j] = 3;
                if (s[j] == 'W') grid[i][j] = 4;
            }
        }

        steps=0;
        solve(0,inicio);

        for (int i = 0; i < n ; i++) for (int j = 0; j < m; j++) vis[i][j] = 0;
    }
    return 0;
}