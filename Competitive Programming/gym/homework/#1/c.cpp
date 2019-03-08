#include <iostream>
using namespace std;

typedef long long ll;

ll tij[9][9]={};
int k, n;

void printMtx() {
    for(int i=0;i<9;i++){
        for(int j=0;j<=i;j++) {
            cout << tij[i][j];
            if(i!=j) cout<<" ";
        }
        cout << endl;
    }
}

int main() {

    int i, j;

    cin>>n;

    for(k=0;k<n;k++) {
        cin>>tij[0][0];
        for(i=0;i<3;i+=2) cin>>tij[2][i];
        for(i=0;i<5;i+=2) cin>>tij[4][i];
        for(i=0;i<7;i+=2) cin>>tij[6][i];
        for(i=0;i<9;i+=2) cin>>tij[8][i];


        //Preencher ultima linha
        tij[8][1]=(tij[6][0]-tij[8][0]-tij[8][2])/2;
        tij[8][3]=(tij[6][2]-tij[8][2]-tij[8][4])/2;
        tij[8][5]=(tij[6][4]-tij[8][4]-tij[8][6])/2;
        tij[8][7]=(tij[6][6]-tij[8][6]-tij[8][8])/2;

        for(i=7;i>=0;i--) for(j=0;j<=i;j++) tij[i][j]=tij[i+1][j]+tij[i+1][j+1];

        printMtx();
    }
    //cout<<endl;

    return 0;
}
