#include<stdio.h>

int main() {

    int a[41][41],i,j,n;
    unsigned long int sum=0;

    scanf("%d",&n);

    for(i=0;i<=n;i++) {
        for(j=i;j>=0;j--) {

            if(i==0) {
                if(j==i) a[i][j]=1;
            } else if(i==1){
                if(j==i) a[i][j]=1;
                if(j==0) a[i][j] = 1;
            } else {
                if(j==i) a[i][j]=1;
                if(j==i-1 && j>0) a[i][j] = a[i-1][j] + a[i-1][j-1];
                if(j<i-1 && j>0) a[i][j] = a[i-1][j-1]+a[i-1][j]+a[i-1][j+1];
                if(j==0) a[i][j] = a[i-1][j]+2*a[i-1][j+1];

            }
        }
    }


    for(i=0;i<=n;i++) {
        for(j=0;j<=i;j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }


    sum = a[n][0];
    for(i=1;i<=n;i++) {
        sum += 2*a[n][i];
    }
    printf("%lu\n",sum);


    return 0;
}
