#include<bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d",&n);
    while(n--){
        string s, b;
        cin>>s;
        cin>>b;
        b=b+b;

        bool has_seq = false;
        for(int i=0;i<b.size();i++){
            int cont=0;
            for(int j=0;j<s.size();j++){
                if(b[i+j]==s[j])cont++;
            }
            if(cont==s.size()) has_seq=true;
        }

        for(int i=b.size()-1;i>=0;i--){
            int cont=0;
            for(int j=0;j<s.size();j++){
                if(b[i-j]==s[j])cont++;
            }
            if(cont==s.size()) has_seq=true;
        }

        printf("%c\n",(has_seq?'S':'N'));
    }
    return 0;
}


