#include<bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define _ << " , " <<
using namespace std;
typedef long long ll;

const int N = 1e6+5;

int n;

int main() {
    scanf("%d",&n);
    if (n == 0) printf("%d\n",1);
    else {
        int resto = n%4;
        if (resto == 1) printf("%d\n",8);
        else if (resto == 2) printf("%d\n",4);
        else if (resto == 3) printf("%d\n",2);
        else if (resto == 0) printf("%d\n",6);
    }    
    return 0;
}