#include<bits/stdc++.h>
#include<locale>
using namespace std;

string s, s_orig;

int main() {
    int p;
    locale loc;
    scanf("%d",&p);
    getline(cin, s);

    while(p--){
        getline(cin, s);
        s_orig=s;
        reverse(s.begin(),s.end());
        bool res=true;
        for(int i=0;i<s.size();i++) {
            if(s[i]>='A' && s[i]<='Z') s[i]=s[i]-'A'+'a';
            if(i!=0 && s[i]==s[i-1]) res=false;
        }



        //printf("Reverse e tolower: %s\n",s.c_str());
        if(res){
            if(next_permutation(s.begin(),s.end())){
                printf("%s: %c\n",s_orig.c_str(),'N');
            }
            else{
                printf("%s: %c\n",s_orig.c_str(),'O');
            }
        } else {
            printf("%s: %c\n",s_orig.c_str(),'N');
        }

    }
    return 0;
}
