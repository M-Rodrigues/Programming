#include<stdio.h>
void printArray(unsigned long int A[], unsigned long int size)
{
    unsigned long int i;
    for (i=0; i < size; i++)
        printf("%lu ", A[i]);
    printf("\n");
}

void merge(unsigned long int arr[], unsigned long int l, unsigned long int m, unsigned long int r)
{
    unsigned long int i, j, k;
    unsigned long int n1 = m - l + 1;
    unsigned long int n2 =  r - m;

    /* create temp arrays */
    unsigned long int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = R[j];//
            j++;
        }
        else
        {
            arr[k] = L[i];//
            i++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(unsigned long int arr[], unsigned long int l, unsigned long int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        unsigned long int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}


int main() {

    double x, aux;
    unsigned long int tiras[100001]={}, n,i,j, altura_corte, last_i, last_j;//Variáveis que armazenam o tamanho das tiras
    unsigned long long int a, sum=0, area_parcial, last_area_parcial; //Variaveis que armazenam a area total

    scanf("%lu%llu",&n,&a);
    while(n!=0 && a!=0) {
        //Segunda linha da entrada
        sum = 0;
        for(i=0;i<n;i++) {
            scanf("%lu",&tiras[i]);
            sum+=tiras[i];
        }
        //printf("\nArea total = %llu\n",sum);

        if(sum == a || a == 0) printf(":D\n");
        else if(sum < a) printf("-.-\n");
        else {
            //Ordenando decrescente
            //printArray(tiras,n);
            n++;
            mergeSort(tiras, 0, n-1);
            //printArray(tiras,n);

            altura_corte=tiras[0];

            i=area_parcial=last_area_parcial=last_i=last_j=0;
            while(i<n-1 && area_parcial < a) {
                last_i=i;
                last_area_parcial = area_parcial;


                j=i+1;
                last_j=j;

                while(tiras[j]==tiras[j+1]) j++;

                altura_corte = tiras[j];
                area_parcial+=(i+1)*(tiras[i]-tiras[j]);

                // /*
                printf("--------------\n");
                printf("i = %lu\n",i);
                printf("j = %lu\n",j);
                printf("tiras[i] = %lu (intervalo superior)\n", tiras[i]);
                printf("tiras[j] = %lu (intervalo inferior)\n", tiras[j]);
                printf("Altura do corte = %lu\n", altura_corte);
                printf("Area acumulada = %llu\n",area_parcial);
                printf("--------------\n");
                // */

                i=j;
            }


            //Caso em que o corte é entre a ultima tira e a base (0)
            if(i==n-1 && area_parcial < a) {
                printf("(Caso entre 0 e a ultima)");
                printf("\nO corte deve ser feito entre %lu e %lu cm\n",tiras[last_i],tiras[i]);
                printf("Ultima soma parcial = %llu\n",area_parcial);
                printf("h1 = %lu\n",altura_corte);
                printf("a = %llu\n",a);
                printf("l_a_p = %lu\n",area_parcial);
                printf("d = %lu\n",n);

                aux = (double)(a-area_parcial)/(double)(n);
                x = (double)tiras[i]-aux;
                printf("%.4lf\n",x);

            } else {
                printf("\nO corte deve ser feito entre %lu e %lu cm\n",tiras[i], 0);
                printf("Ultima soma parcial = %llu\n",last_area_parcial);
                printf("h1 = %lu\n",tiras[last_i]);
                printf("a = %llu\n",a);
                printf("l_a_p = %lu\n",last_area_parcial);
                printf("d = %lu\n",last_j);

                //Caso em que todas as tiras tem o mesmo tamanho
                if((tiras[last_i]==tiras[i])&&(last_i!=i)) last_j=n;

                printf("d = %lu\n",last_j);

                aux = (double)(a-last_area_parcial)/(double)(last_j);
                x = (double)tiras[last_i]-aux;
                printf("%.4lf\n",aux);
                printf("%.4lf\n",x);
            }
        }

        scanf("%lu%llu",&n,&a);
    }

    return 0;
}
