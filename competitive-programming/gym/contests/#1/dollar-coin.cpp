#include<bits/stdc++.h>
using namespace std;

char coin;
string l[3], r[3], res[3], test[3], type;
int n;

void isHeavy(char c, int n){
    int cont_l=0, cont_r=0;

    test[n]="";

    for(int i=0;i<l[n].size();i++) if(l[n][i]!=c) cont_l++;
    if(cont_l!=l[n].size()) {test[n]="up"; /*cout<<"Moeda esta na esquerda"<<endl;*/}

    for(int i=0;i<r[n].size();i++) if(r[n][i]!=c) cont_r++;
    if(cont_r!=r[n].size()) {test[n]="down";  /*cout<<"Moeda esta na direita"<<endl;*/}

    if(cont_l==l[n].size() && cont_r==r[n].size()) {test[n]="even"; /*cout<<"Moeda em nenhuma balanca"<<endl;*/}
}

void isLight(char c, int n){
    int cont_l=0, cont_r=0;

    test[n]="";

    for(int i=0;i<l[n].size();i++) if(l[n][i]!=c) cont_l++;
    if(cont_l!=l[n].size()) {test[n]="down"; /*cout<<"Moeda esta na esquerda"<<endl;*/}

    for(int i=0;i<r[n].size();i++) if(r[n][i]!=c) cont_r++;
    if(cont_r!=r[n].size()) {test[n]="up";  /*cout<<"Moeda esta na direita"<<endl;*/}

    if(cont_l==l[n].size() && cont_r==r[n].size()) {test[n]="even"; /*cout<<"Moeda em nenhuma balanca"<<endl;*/}
}

int check(char c){
    //cout<<"Testando "<<(char)(c+'A')<<endl;
    type="light";


    for(int i=0;i<3;i++){
        //cout<<"Pesagem numero "<<i+1<<endl;
        isLight((char)(c+'A'),i);
        //cout<<"Balanca deveria marcar: "<<test[i]<<endl;
    }
    if((res[0]==test[0])&&(res[1]==test[1])&&(res[2]==test[2])) return c;


    type="heavy";



    for(int i=0;i<3;i++){
       // cout<<"Pesagem numero "<<i+1<<endl;
        isHeavy((char)(c+'A'),i);
        //cout<<"Balanca deveria marcar: "<<test[i]<<endl;
    }
    if((res[0]==test[0])&&(res[1]==test[1])&&(res[2]==test[2])) return c;

    //cout<<"------------"<<endl;
    return -1;

}

int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++) cin>>l[j]>>r[j]>>res[j];
        for(int i=0;i<12;i++) {coin=check(i); if(coin>=0) break;}
        cout<<(char)(coin+'A')<<" is the counterfeit coin and it is "<<type<<"."<<endl;
    }

    return 0;
}
