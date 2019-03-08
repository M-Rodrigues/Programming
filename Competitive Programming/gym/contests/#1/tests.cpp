#include <bits/stdc++.h>
using namespace std;

long long power(int a, int b){
    if(b==1) return a;
    return a*power(a,b-1);
}

int main() {

  long long aux=power(2,40);
  printf("%lli",aux);

}
