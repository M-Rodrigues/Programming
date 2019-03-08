#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int index = 0, n = gas.size();
        
        int val = gas[0] - cost[0];
        int sum = val;
        for (int i = 1; i < n; i++) {
            int aux = gas[i] - cost[i];
            printf("%d -: %d :: %d\t%d\n",i,aux,val,sum);
            if (aux > val) {
                val = aux;
                index = i;
            }
            
            sum += aux;
        }
        
        if (sum < 0) return -1;
        return index;
    }
};

int main() {
    Solution q;
    vector<int> gas({5,1,2,3,4});
    vector<int> cost({4,4,1,5,1});

    cout << q.canCompleteCircuit(gas, cost) << endl;

    return 0;
}