#include<bits/stdc++.h>
using namespace std;

int n, aux, a[1001];

bool solve() {
    stack<int> s;
    int i=0,k=0;

    for(int i=0;i<n;i++){
        while(s.size() && s.top()==k+1){
            k++;
            s.pop();
        }
        if(a[i]!=k+1) s.push(a[i]);
        else k++;
    }
    while(s.size() && s.top()==k+1){
        k++;
        s.pop();
    }
    return (k==n ? true : false);
}
int main(){
    scanf("%d",&n);
    while(n!=0){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        printf("%s\n",(solve()?"yes":"no"));
        scanf("%d",&n);
    }
    return 0;
}
