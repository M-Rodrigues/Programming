#include<iostream>
#include<string>
using namespace std;

string pos(double x, double y) {
    if(x > 0 && y > 0) return "Q1";
    if(x < 0 && y > 0) return "Q2";
    if(x < 0 && y < 0) return "Q3";
    if(x > 0 && y < 0) return "Q4";
    if(x == 0 && y != 0) return "Eixo Y";
    if(x != 0 && y == 0) return "Eixo X";
    if(x == 0 && y ==0) return "Origem";
}

int main() {

    double x, y;

    cin >> x >> y;
    cout << pos(x,y) << endl;

    return 0;
}

