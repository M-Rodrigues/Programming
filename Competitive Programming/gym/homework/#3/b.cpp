#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector< pair<int, int> > p;
int x, y;

void testing(pair<int,int> p){ printf("Testando: (%d,%d)\n",p.first,p.second); }

int dd (int x, int y){ return (x*x)+(y*y); }

int dist(pair<int, int> a, pair<int, int> b){ return dd(a.first-b.first,a.second-b.second); }

bool chk_right(pair<int, int> a, pair<int, int> b, pair<int, int> c){
    int ab = dist(a,b);
    int bc = dist(b,c);
    int ac = dist(c,a);

    return ab>0 && bc>0 && ac>0 && ab==bc+ac;
}

bool chk_almost(int i) {
    pair<int, int> a = p[i%3];
    pair<int, int> b = p[(i+1)%3];
    pair<int, int> c = p[(i+2)%3];

    a.first++;
    if(chk_right(a,b,c)) return true;
    if(chk_right(b,c,a)) return true;
    if(chk_right(c,a,b)) return true;

    a.first-=2;
    if(chk_right(a,b,c)) return true;
    if(chk_right(b,c,a)) return true;
    if(chk_right(c,a,b)) return true;

    a.first++;

    a.second++;
    if(chk_right(a,b,c)) return true;
    if(chk_right(b,c,a)) return true;
    if(chk_right(c,a,b)) return true;

    a.second-=2;
    if(chk_right(a,b,c)) return true;
    if(chk_right(b,c,a)) return true;
    if(chk_right(c,a,b)) return true;

    a.second++;
    return false;
}

int main() {
    for(int i=0; i<3; i++){
        scanf("%d%d",&x,&y);
        p.push_back(make_pair(x,y));
    }

    bool right=false, almost=false;


    for(int i=0; i<3; i++) if(chk_right(p[(i)%3],p[(i+1)%3],p[(i+2)%3])) right=true;
    if(!right) for(int i=0; i<3; i++) if(chk_almost(i)) almost=true;


    if(right) printf("RIGHT\n");
    else if(almost) printf("ALMOST\n");
    else printf("NEITHER\n");

}
