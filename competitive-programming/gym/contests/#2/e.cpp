#include<bits/stdc++.h>
using namespace std;

int main() {
    string s, nomes[5]={"Danil","Olya","Ann","Slava","Nikita"};
    int cont=0;

    cin>>s;
    int total=0;
    for(int i=0;i<5;i++){
        if(s.size()>=nomes[i].length()){
            //cout<<nomes[i]<<" : "<<nomes[i].length()<<endl;
            for(int j=0;j<s.size()-nomes[i].length()+1;j++){
                int cont=0;
                for(int k=0;k<nomes[i].length();k++){
                    if(s[j+k] == nomes[i][k]) cont++;
                }
                if(cont==nomes[i].length()) total++;
            }
        }
    }

    if(total==1) printf("YES\n");
    else printf("NO\n");

    return 0;
}


