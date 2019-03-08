#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,n1,d1,n2,d2,num,dem;
char c1,c2,op;

int gcd(int a, int b){
    if(a<b) swap(a,b);
    if(a<0) a=-a;
    if(b<0) b=-b;
    if(b==0) return a;
    return gcd(b,a%b);
}

void result(char op){
    if(op=='+'){
        num = n1*d2+n2*d1;
        dem = d1*d2;
    }
    if(op=='-'){
        num = n1*d2-n2*d1;
        dem = d1*d2;
    }
    if(op=='/'){
        num = n1*d2;
        dem = n2*d1;
    }
    if(op=='*'){
        num = n1*n2;
        dem = d1*d2;
    }
}

int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d %c %d %c %d %c %d",&n1,&c1,&d1,&op,&n2,&c2,&d2);
        result(op);  
        printf("%d/%d = %d/%d\n",num,dem,num/gcd(num,dem),dem/gcd(num,dem));
    }
    return 0;
}