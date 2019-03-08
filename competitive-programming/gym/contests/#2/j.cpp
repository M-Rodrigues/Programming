#include<bits/stdc++.h>
using namespace std;


string s;

int main() {
    int n;
    scanf("%d",&n);
    getline(cin,s);

    for(int i=0;i<n;i++){
        getline(cin, s);
        //cout<<"Tamanho: "<<s.size()<<endl;

        stack<char> p;
        bool res=true;
        if(s.size()==0) res=true;
        else {
            for(int j=0;j<s.size();j++){
                if(p.empty()) {
                    if(s[j]=='(' || s[j]=='['){
                        p.push(s[j]);
                    } else {
                        res=false;
                    }
                } else {
                    if(s[j]=='(' || s[j]=='[') p.push(s[j]);
                    else {
                        if(p.top()=='(' && s[j]==')') p.pop();
                        else if(p.top()=='[' && s[j]==']') p.pop();
                        else res=false;
                    }
                }
            }
        }
        s.clear();
        printf("%s\n",((res&&p.empty())?"Yes":"No"));
    }
    return 0;
}

