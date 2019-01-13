#include<bits/stdc++.h>
using namespace std;

int w,h,n, t[500][500]={}, k;

void swap(int *a, int *b){
    int aux = *a;
    *a=*b;
    *b=aux;
}

void zeroMTX(){ for(int i=0;i<500;i++) for(int j=0;j<500;j++) t[i][j]=0; }

void printMTX(int w, int h) {
    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++){
            cout<<t[i][j];
        }
        cout<<endl;
    }
}

int main() {
    cin>>w>>h>>n;
    while(w+h+n!=0){
        k=n;
        int count=w*h;
        zeroMTX();

        while(k--){
            int x1,x2,y1,y2;
            cin>>x1>>y1>>x2>>y2;
            /*
            cout<<"Entrada:"<<endl;
            cout<<"Ponto 1: ("<<x1<<","<<y1<<")"<<endl;
            cout<<"Ponto 2: ("<<x2<<","<<y2<<")"<<endl;
            cout<<"---------"<<endl;
            */
            if(x1>x2) swap(&x1,&x2);
            if(y1>y2) swap(&y1,&y2);

            x1--;x2--;y1--;y2--;
            for(int i=y1;i<=y2;i++){
                for(int j=x1;j<=x2;j++){
                    if(t[i][j]==0){
                        count--;
                        t[i][j]=1;
                    }
                }
            }

            //printMTX(w,h);
            //cout<<"--------"<<endl;
            /*
            cout<<"Entrada ordenada:"<<endl;
            cout<<"Ponto 1: ("<<x1<<","<<y1<<")"<<endl;
            cout<<"Ponto 2: ("<<x2<<","<<y2<<")"<<endl;
            */
        }


        //for(int i=0;i<h;i++) for(int j=0;j<w;j++) if(t[i][j]==0) count++;
        if(count==0) cout<<"There is no empty spots."<<endl;
        else if(count==1) cout<<"There is one empty spot."<<endl;
        else cout<<"There are "<<count<<" empty spots."<<endl;

        cin>>w>>h>>n;
    }

    return 0;
}
