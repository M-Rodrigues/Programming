#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
string line;

ll strToInt(ll tam){
    if(tam==0) return 0;
    return (int)(line[tam-1]-'0')+strToInt(tam-1);
}

ll countDigits(ll n){
    if(n>=0&&n<=9) return n;
    return n%10+(countDigits((n-n%10)/10));
}

int main() {

    getline(cin, line);

    while(line[0]!='0'){
        n=strToInt(line.size());
        while(n>=10) n = countDigits(n);
        cout<<n<<endl;
        getline(cin, line);
    }


    return 0;
}
