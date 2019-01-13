#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {
    int n;
    scanf("%d",&n);

    stack<string> d;
    string s;
    while(n--){
        cin>>s;
        if(s=="Test") {
            //printf("Fazer o top()\n");
            if(d.empty()) printf("Not in a dream\n");
            else printf("%s\n",d.top().c_str());
        } else if(s=="Kick") {
            //printf("Fazer o pop()\n");
            if(!d.empty()) d.pop();
        } else {
            cin>>s;
            //printf("Estou no sonho do %s\n",s.c_str());
            d.push(s);
        }


    }
    return 0;
}
