#include<iostream>
#include<string>
using namespace std;
int freq[26]={};

void zeroArray() {
    for(int i=0;i<26;i++) freq[i]=0;
}

int main() {

    char c;
    int n,maior=0,i;
    string line;

    cin>>n;
    getline(cin, line);
    while(n--) {
        zeroArray();
        maior=0;
        getline(cin, line);

        for(i=0;i<line.size();i++){
            if(line[i]>='a'&&line[i]<='z'){
                freq[line[i]-'a']++;
                if(freq[line[i]-'a']>maior) maior=freq[line[i]-'a'];
            } else if(line[i]>='A'&& line[i]<='Z'){
                freq[line[i]-'A']++;
                if(freq[line[i]-'A']>maior) maior=freq[line[i]-'A'];
            }
        }
        for(i=0;i<26;i++) if(freq[i]==maior) cout << (char)(i+'a');
        cout<<endl;

    }


    return 0;
}
