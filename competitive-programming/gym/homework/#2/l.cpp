#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, d;
    scanf("%d%d",&a,&d);
    while(a!=0 && d!=0){
        int a_max;
        for(int i=0;i<a;i++){
            int aux;
            scanf("%d",&aux);
            if(i==0) a_max=aux;
            else if(aux<a_max) a_max=aux;
        }
        //cout<<"Atacante mais avancado: "<<a_max<<endl;

        int aux, ultimo, penultimo;
        for(int i=0;i<d;i++){
            scanf("%d",&aux);
            if(i==0) ultimo=aux;
            else if(i==1){
                if(aux<ultimo){
                    penultimo=ultimo;
                    ultimo=aux;
                } else {
                    penultimo=aux;
                }
            } else {
                if(aux<ultimo){
                    penultimo=ultimo;
                    ultimo=aux;
                } else if(aux<penultimo) penultimo=aux;
            }
        }
        //cout<<"Defensores mais recuados: "<<penultimo<<" "<<ultimo<<endl;
        printf("%c\n",(a_max<penultimo)?'Y':'N');

        scanf("%d%d",&a,&d);
    }
    return 0;
}
