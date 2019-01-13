#include<bits/stdc++.h>
using namespace std;

string s;
int n, l, c;
long long int totalC, totalL, totalP;

int main() {
    while (cin >> n >> l >> c) {
        totalC = totalL = totalP = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> s;
            totalC += s.size();
        }
        totalC += n-1;
        totalL = totalC/c;
        if (totalC % c != 0) totalL++;
        totalP = totalL/l;
        if (totalL % l != 0) totalP++;
        cout << totalP << endl;
    }
    return 0;
}