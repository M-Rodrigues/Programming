#include<iostream>
#include<string>
using namespace std;

int leds(char c){
    switch (c){
        case '0': return 6; break;
        case '1': return 2; break;
        case '2': return 5; break;
        case '3': return 5; break;
        case '4': return 4; break;
        case '5': return 5; break;
        case '6': return 6; break;
        case '7': return 3; break;
        case '8': return 7; break;
        case '9': return 6; break;

    }

}

int main() {

    int n;
    string line;

    cin>>n;
    getline(cin, line);
    while(n--){
        long long soma=0;
        getline(cin, line);
        for(int i=0;i<line.size();i++){
            soma+=leds(line[i]);
        }
        cout<<soma<<" leds"<<endl;
    }

    return 0;
}

