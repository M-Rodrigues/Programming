#include<bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define _ << " , " <<
using namespace std;
typedef long long ll;

const int N = 1e6+5;

string s, b = "bear";
set<pair<int,int>> pairs;

int p[5000][5000];

int main() {
    cin>>s;

    int len = s.size();
    int ans = 0;
    int last_i = -1;

    if (len >= 4) {
        for (int i = 0 ; i <= len-4 ; i++) {
            bool has = true;

            for (int j = 0 ; j < 4 ; j++) {
                if (s[i+j] != b[j]) has = false;
                if(!has) break;
            }

            if (has){
                int I=i, J=i+3;
                
                //printf("Tem 'bear' na posicao (%d, %d)\n",I,J);
                // for(int p1 = I ; p1 >= 0 ; p1--) {
                //     for (ll p2 = J ; p2 < len ; p2++) {
                //         if (p[p1][p2] == 0)
                //             p[p1][p2] = 1, ans++;
                //     }
                // }

                ans += (i+1)*(len-i-3);
                ans -= (last_i+1)*(len-i-3);

                last_i=i;

                i+=3;
            }
        }
    }
    printf("%d\n",ans);
    
    return 0;
}