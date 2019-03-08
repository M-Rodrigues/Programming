#include<bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define _ << " , " <<
using namespace std;
typedef long long ll;

const int N = 1e6+5;

int n, a;
vector<pair<int,int>> pairs;

int main() {
    scanf("%d",&n);

    for (int i = 0; i < n; i++){
        scanf("%d",&a);
        pairs.push_back(make_pair(a,i));
    }

    sort(pairs.begin(),pairs.end());

    for (int i = 0; i < n/2; i++){
        printf("%d %d\n",pairs[i].second+1,pairs[n-i-1].second+1);
    }

    return 0;
}