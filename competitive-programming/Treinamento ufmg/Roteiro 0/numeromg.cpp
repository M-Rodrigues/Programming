#include <iostream>
#include<string>
using namespace std;

string a, b;

unsigned long long power(int a, unsigned long long b){
    if (b==0) return 1;
    return a*power(a,b-1);
}

int main () {

    unsigned long long int n_a, n_b, i, pot, n_sum, tam;
    char sum[10000], aux[10000];


    cin >> a;
    cin >> b;

    while(a[0]!='0' && b[0]!=0) {
        //cout << "dentro do while" << endl;

        n_a=0;
        for(i=0;i<a.size();i++){
            pot = power(36,a.size()-i-1);

            if(a[i]>='A' && a[i]<='Z') {
                n_a += ((int)a[i]-55)*pot;
            }
            if(a[i]>='0' && a[i]<='9') {
                n_a += ((int)a[i]-48)*pot;
            }
        }
        //cout << "a to dec: " << n_a << endl;

        n_b = 0;
        for(i=0;i<b.size();i++){
            pot = power(36,b.size()-i-1);

            if(b[i]>='A' && b[i]<='Z') {
                n_b += ((int)b[i]-55)*pot;
            }
            if(b[i]>='0' && b[i]<='9') {
                n_b += ((int)b[i]-48)*pot;
            }
        }
        //cout << "b to dec: " << n_b << endl;

        n_sum = n_a + n_b;

        //cout << "soma: " << n_sum << endl;
        i=0;
        while(n_sum!=0) {
            //cout << "dentro do while" << endl;
            //cout << "soma: " << n_sum << endl;
            //cout << "resto: " << n_sum%36 << endl;
            if(n_sum%36 >=0 && n_sum%36 <= 9) sum[i]=(char)(n_sum%36)+48;
            else sum[i]=(char)(n_sum%36)+55;
            n_sum = (n_sum-n_sum%36)/36;

            i++;
        }
        sum[i]='\0';
        tam = i;

        //cout << "soma na base estranha: " << sum << endl;

        for(i=0;i<=tam;i++) aux[i]=sum[tam-i-1];

        cout << aux << endl;


        cin >> a;
        cin >> b;
    }
    return 0;
}
