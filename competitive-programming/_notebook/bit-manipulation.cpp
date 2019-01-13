#include <bits/stdc++.h>
using namespace std;

bool getBit(int num, int i) {
    return (num & (1 << i)) != 0;
}

int setBit(int num, int i) {
    return num | (1 << i);
}

int clearBit(int num, int i) {
    return num & ~(1 << i);
}

int clearBitsMStoI(int num, int i) {
    return num & ((1 << i) - 1);
}

int clearBitsIto0(int num, int i) {
    return num & (-1 << (i + 1));
}

int updateBit(int num, int i, bool bit) {
    int x = bit ? 1 : 0; 
    return (num & ~(1 << i)) | (x << i);
}

int getMSBit(int num) {
    int i = 1;
    while (clearBitsMStoI(num,i) != num) i++;
    return i;
}

int getLSBit(int num) {
    int i = 1;
    while (clearBitsMStoI(num,i) != (1 << (i - 1))) i++;
    return i;
}

int bitsToFlip(int a, int b) {
    int n = getMSBit(a);
    int i = 1;
    int count = 0;

    while (i <= n) {
        if (getBit(a,i) ^ getBit(b,i)) count++;
        i++;
    }
    return count;
}

int main() {
    int x = 5;
    bitset<15> x_bits = x;

    cout << x_bits << endl;
    cout << endl;

    cout << getBit(x,0)<< endl;
    cout << getBit(x,1)<< endl;
    cout << getBit(x,2)<< endl;
    cout << endl;

    cout << setBit(x,1)<< endl;
    cout << setBit(x,5)<< endl;
    cout << endl;

    cout << clearBitsIto0(x, 0) << endl;
    cout << clearBitsIto0(x, 1) << endl;
    cout << clearBitsIto0(x, 2) << endl;
    cout << endl;

    cout << clearBitsMStoI(x,0) << endl;
    cout << clearBitsMStoI(x,1) << endl;
    cout << clearBitsMStoI(x,2) << endl;
    cout << clearBitsMStoI(x,3) << endl;
    cout << endl;

    cout << clearBit(x,0) << endl;
    cout << clearBit(x,1) << endl;
    cout << clearBit(x,2) << endl;
    cout << endl;

    cout << updateBit(x,1,true) << endl;
    cout << endl;

    cout << getMSBit(x) << endl;
    cout << getLSBit(x) << endl;
    cout << endl;

    cout << bitsToFlip(229,155) << endl;
    cout << endl;

    return 0;
}