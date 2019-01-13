#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {

    double x1,x2,y1,y2,dist;

    cin >> x1 >> y1 >> x2 >> y2;

    dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

    cout << fixed;
    cout << setprecision(4) << dist << endl;

    return 0;
}

