#include<iostream>
#include<string>
using namespace std;

int main() {

    char c;
    string line,aux;

    while(true){
        cin>>c;
        getline(cin, line);

        if(c=='0' && line[1]=='0') break;

        for(int i=1;i<line.size();i++){
            if(line[i]!=c){
                if(line[i]=='0'){
                    if(aux.size()!=0) {
                    aux.append(sizeof(char),line[i]);
                    }
                } else aux.append(sizeof(char),line[i]);
            }
        }

        if(aux.size()==0)aux.append(sizeof(char),'0');

        cout<<aux<<endl;
        aux.clear();
    }

    return 0;
}

