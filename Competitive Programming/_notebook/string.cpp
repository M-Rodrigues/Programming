#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

// Z-function
int z[N];

void z_func(string &s) {
    int x, y; x = y = 0;

    z[0]=0;
    for (int i = 1; i < s.size(); i++) {
        z[i] = max(0,min(y-i,z[i-x]));

        while (z[i]+i < s.size() and s[z[i]] == s[z[i] + i])
            x = i, z[i]++, y = z[i]+i;
    }
}

int a[3] = {2,5,8};

void funcao(int * v) {
    printf("%d\n",v[2]);
}

int main() {
    funcao(a);

    // Z-function
    string s = "atavatavatavatavg";
    z_func(s);
    for (int i = 0; i < s.size(); i++) printf("%d ",z[i]); printf("\n");
    
    // Buscar período
    int T = 0;
    for (int i = 0; i < s.size(); i++) if (i+z[i] == s.size() and s.size()%i == 0) { T = i; break; }

    if (T != s.size()) printf("Período da string: %d\n",T);
    else printf("A string não possui período...\n");

    // String matching
    string ss = "ba";
    string sss = ss + "$";
    sss += s;

    z_func(sss);
    for (int i = 0; i < sss.size(); i++) printf("%d ",z[i]); printf("\n");

    bool ok = false;
    for (int i = 0; i < sss.size(); i++) if (z[i] == ss.size()) { ok = true; break; }

    if (ok) printf("Existe substring!\n");
    else printf("Não existe...\n");

    // String shifting
    string a, b;
    a = "abac";
    b = "acab";

    string t = a + a;
    t = b + "$" + t;
    z_func(t);
    for (int i = 0; i < t.size(); i++) printf("%d ",z[i]); printf("\n");

    ok = false;
    for (int i = 0; i < t.size(); i++) if (z[i] == b.size()) { ok = true; break; }

    if (ok) printf("Existe substring shifting!\n");
    else printf("Não existe shift...\n");

    return 0;
}