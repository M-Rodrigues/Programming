#include <iostream>
#include <iomanip>
using namespace std;

#define PI 3.14159

int main() {

    double r, area;

    cin >> r;

    area = PI*r*r;

    cout << fixed;
    cout << "A=";
    cout << setprecision(4) << area << endl;

    return 0;
}
