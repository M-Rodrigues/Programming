#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl
#define _ << " , " <<

typedef long long ll;
typedef long double ld;

const int N = 1e5+5;

void showVector(vector<int> & data) {
    for(int i = 0; i < data.size(); i++) printf("%d ",data[i]);
    printf("\n");
}

int n;
vector<int> A, B;

int main() {
    scanf("%d",&n);

    A.pb(1);
    B.pb(0);

    for (int i = 0; i < n ; i++) {
        vector<int> aux;
        aux = A;

        //  Shift do A;
        A.pb(0);
        for (int i = A.size() - 1; i > 0; i--) A[i] = A[i-1];
        A[0] = 0;

        //  Soma com B e tira mod 2
        for (int i = 0; i < B.size(); i++) A[i] = (A[i] + B[i])%2;

        //  B vira antigo A
        B = aux;
        aux.clear();
    }

    printf("%d\n",(int)A.size()-1);
    showVector(A);
    printf("%d\n",(int)B.size()-1);
    showVector(B);

    return 0;
}