#include<stdio.h>
void zeros(int A[]) {
    int i;
    for (i=0; i < 1000; i++) A[i]=0;
}

int main() {

    char c;
    int qtde_letras[1000], n_impar = 0;

    zeros(qtde_letras);

    while(scanf("%c",&c) != EOF) {

        if(c == '\n') {
            //Ver qnts letras faltam
            if (n_impar == 0) n_impar++;
            printf("%d\n",n_impar - 1);

            //Reiniciar variáveis
            n_impar=0;
            zeros(qtde_letras);
        } else {
            qtde_letras[c]++;

            if(qtde_letras[c]%2==1) n_impar++;
            else n_impar--;
        }
    }

    return 0;
}
