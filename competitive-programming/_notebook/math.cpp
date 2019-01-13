#include <bits/stdc++.h>
typedef long long ll;
/*****************************************************************************************************/
//
//                                    NUMBER THEORY                                                  //
//
/*****************************************************************************************************/

/*      FAST EXPONETIATION      */
int fexp(int a, int b)
{ //Recursive
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return fexp(a * a, b / 2);
    return a * fexp(a * a, b / 2);
}

int fexp(int a, int b)
{ //Iterative
    int res = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            res *= a;
        a *= a;
        b /= 2;
    }
    return res;
}

/*      FAST MODULAR EXPONETIATION      */
int fmexp(int a, int b, int m)
{ //Recursive
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return fexp((a * a) % m, b / 2);
    return (a * fexp((a * a) % m, b / 2)) % m;
}

int fmexp(int a, int b, int m) { //Iterative
    int res = 1;
    while (b > 0) {
        if (b % 2 == 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return res;
}

/*      GCD (ou mdc)        */
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

/*      EXTENDED EUCLIDES ALGORITHM     */
// Ax + By = gcd(A,B) => encontrar x e y
int d, x, y;
void extendedEuclid(int A, int B)
{
    if (B == 0)
    {
        d = A;
        x = 1;
        y = 0;
    }
    else
    {
        extendedEuclid(B, A % B);
        int temp = x;
        x = y;
        y = temp - (A / B) * y;
    }
}

/*      MODULAR MULTIPLICATIVE INVERSE      */
// A.B = 1 (mod m) => B é o inverso multiplicativo de A mod m

int modInv(int A, int m)
{ // Quando A e m são primos entre si
    int d, x, y;
    extendedEuclid(A, m);
    return (x % m + m) % m; //x may be negative
}

int modInv(int A, int m)
{ // Quando m é primo => Pequeno Teorema de Fermat
    return fmexp(A, m - 2, m);
}

/*      EULER'S TOTIENT FUNCTION    */
// phi(n) => diz a quantidade de números menores ou iguais a n que são primos entre si com n

int totient(int n)
{
    int phi = n;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i) && n % i == 0)
            phi = phi * (i - 1) / i;
    }
    return phi;
}

/*      ERATÓSTENES'S SIEVE    */
const int N = 1e6 + 6;
int cmp[N];
vector<int> p;

void primes()
{
    //  No início tenho cmp[N] = {0,0,0,...,0}
    //  No final, terei um vector com todos os primos menores que N
    for (ll i = 2; i * i <= N; i++)
        if (!cmp[i])
        {
            for (ll j = i * i; j < N; j++)
                cmp[j] = 1;
        }
    for (ll i = 2; i < N; i++)
        if (!cmp[i])
            p.push_back(i);
}

/*****************************************************************************************************/
//
//                                    COMBINATORICS                                                  //
//
/*****************************************************************************************************/

/*      FACTORIAL       */
int fat(int n)
{
    if (n == 0)
        return 1;
    int res = 1;
    for (int i = 1; i <= n; i++)
        res *= i;
    return res;
}

int comb(int n, int k)
{
}
