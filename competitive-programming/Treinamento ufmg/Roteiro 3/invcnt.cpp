#include<bits/stdc++.h>
using namespace std;

#define INF 1e7+1

int mergeSort(vector<int> &v){
    int cont=0;

    if(v.size()==1) return 0;

    vector<int> v1,v2;
    for(int i=0;i<v.size()/2;i++) v1.push_back(v[i]);
    for(int i=v.size()/2;i<v.size();i++) v2.push_back(v[i]);

    cont+=mergeSort(v1);
    cont+=mergeSort(v2);

    v1.push_back(INF);
    v2.push_back(INF);

    int i=0,j=0;
    for(int k=0;k<v.size();k++){
        if(v1[i]<=v2[j]){
            v[k]=v1[i];
            i++;
        } else {
            v[k]=v2[j];
            j++;
            cont+=v1.size()-i-1;
        }
    }
    v1.clear();
    v2.clear();
    return cont;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<int> v(n);

        for(int i=0;i<n;i++) scanf("%d",&v[i]);

        printf("%d\n",mergeSort(v));
        v.clear();
    }
    return 0;
}
