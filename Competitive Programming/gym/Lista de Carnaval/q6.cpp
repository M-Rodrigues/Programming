#include<stdio.h>

int main() {

    int i,f1=0,f2=1,f3,n;

    scanf("%d",&n);

    for(i=0;i<n;i++) {
        if(i == 0) printf("%d ",f1);
        if(i == 1) printf("%d ",f2);
        if(i >= 2){
            f3=f2+f1;
            f1=f2;
            f2=f3;
            if(i == n-1) printf("%d\n",f3);
            else printf("%d ",f3);
        }
    }

    return 0;
}
