#include<bits/stdc++.h>
#include<string>
using namespace std;

typedef long long ll;

int n,m,s,r_x,r_y;
char rali[100][100], r_ori;
string line, instr;

void printMTX(int w, int h) {
    //cout<<"Matriz rali"<<endl;
    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++){
            cout<<rali[i][j];
        }
        cout<<endl;
    }
}

char new_ori(char ori, char d){
    if(d=='D'){
        //cout<<"Virar a direita"<< endl;
        if(ori=='N') return 'L';
        if(ori=='L') return 'S';
        if(ori=='S') return 'O';
        if(ori=='O') return 'N';
    }
    if(d=='E'){
        //cout<<"Virar a esquerda"<<endl;
        if(ori=='N') return 'O';
        if(ori=='O') return 'S';
        if(ori=='S') return 'L';
        if(ori=='L') return 'N';
    }
    if(d=='F'){
        //cout<<"Verificar se pode ir em frente"<<endl;
        return ori;
    }

}

int new_pos(){
    bool can_move=true;

    //Verificar se não ultrapassará as bordas e se não tem parede #
    if(r_ori=='N' && (r_y==0 || rali[r_y-1][r_x]=='#')) can_move=false;
    if(r_ori=='S' && (r_y==n-1 || rali[r_y+1][r_x]=='#')) can_move=false;
    if(r_ori=='L' && (r_x==m-1 || rali[r_y][r_x+1]=='#')) can_move=false;
    if(r_ori=='O' && (r_x==0 || rali[r_y][r_x-1]=='#')) can_move=false;

    //Fazer movimento de acordo com a orientação e atualizar a posicao do robo
    //cout<<"Posso me mover? "<<((can_move) ? "SIM" : "NAO")<<endl;

    //cout<<"Posicao atual: ("<<r_x<<","<<r_y<<")"<<endl;


    if(can_move){
        if(r_ori=='N'){
            //cout<<"if N"<<endl;
            r_y--;
        } else
        if(r_ori=='L'){
            //cout<<"if L"<<endl;
            r_x++;
        } else
        if(r_ori=='S'){
            //cout<<"if S"<<endl;
            r_y++;
        } else
        if(r_ori=='O'){
            //cout<<"if O"<<endl;
            r_x--;
        }
        //cout<<"Posicao seguinte: ("<<r_x<<","<<r_y<<")"<<endl;
        //cout<<"Item: "<<rali[r_y][r_x]<<endl;
        if(rali[r_y][r_x]=='*'){
            rali[r_y][r_x]='.';
            return 1;
        }
    }
    return 0;
}

int pegar_figurinhas(){
    int cont;
    cont=0;
    //cout<<"Caminhando com o robo: "<<instr<<endl;
    for(int i=0;i<s;i++){
        //cout<<endl;
        //cout<<"Passo "<<i<<":"<<instr[i]<<endl;

        //Nova orientacao do robo
        r_ori=new_ori(r_ori,instr[i]);

        //Verificar se pode ir a frente
        if(instr[i]=='F') cont+=new_pos();

        //cout<<"Orientacao: "<<r_ori<<endl;
        //cout<<"Proxima orientacao: "<<new_ori(r_ori,instr[i])<<endl;
        //cout<<"Tesouros: "<<cont<<endl;
    }
    return cont;
}

int main() {
    cin>>n>>m>>s;
    getline(cin, line);
    while(n+m+s!=0){
        for(int i=0;i<n;i++){
            getline(cin, line);
            //cout<<"debug: "+line<<endl;

            for(int k=0;k<m;k++){
                if(line[k]=='.') rali[i][k]='.';
                if(line[k]=='*') rali[i][k]='*';
                if(line[k]=='#') rali[i][k]='#';
                if(line[k]=='N' || line[k]=='S' || line[k]=='L' || line[k]=='O') {
                    rali[i][k]='.';
                    r_y=i;
                    r_x=k;
                    r_ori=line[k];
                }
            }
        }
        getline(cin, instr);

        //cout<<"Orientacao inicial do robo: "<<r_ori<<endl;


        int fig=0;
        fig=pegar_figurinhas();
        cout<<fig<<endl;

        cin>>n>>m>>s;
        getline(cin, line);
    }


    return 0;
}
