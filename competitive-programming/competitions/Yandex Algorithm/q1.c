#include<stdio.h>

int main() {
    int x, y;

    scanf("%d%d", &x,&y);

    x = 12 - x;
    y = 60 - y;

    if (x == 12) x = 0;
    if (y == 60) y = 0;

    printf("%d %d\n",x,y);

    return 0;
}
