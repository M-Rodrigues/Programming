#include <iostream>
using namespace std;

int main () {

    int n, a[70][70], i, j;

    while(cin >> n) {
        for(i=0;i<n;i++) {
            for(j=0;j<n;j++) {
                if(i==j && n-j-1!=i) a[i][j]=1;
                else if(n-j-1==i) a[i][j]=2;
                else a[i][j]=3;
            }
        }

        for(i=0;i<n;i++) {
            for(j=0;j<n;j++) {
                cout << a[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}

