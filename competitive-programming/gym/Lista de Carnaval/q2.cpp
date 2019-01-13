#include<stdio.h>

int main() {
	int n, pt_a, pt_b, a, b, i;

    scanf("%d",&n);

    while(n != 0) {
        pt_a = pt_b = 0;

        for(i=0;i<n;i++) {
            scanf("%d%d",&a,&b);
            if(a > b) pt_a++;
            if(a < b) pt_b++;
        }

        printf("%d %d\n",pt_a,pt_b);

        scanf("%d",&n);
    }

	return 0;
}
