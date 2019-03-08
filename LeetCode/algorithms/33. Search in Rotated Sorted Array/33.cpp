#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums, 0, nums.size()-1);
        cout << pivot << endl;
        
        int id1 = bs(nums, 0, pivot, target);
        cout << id1 << endl;
        int id2 = bs(nums, pivot+1, nums.size()-1, target);
        cout << id2 << endl;

        return id1 == -1 ? id2 == -1 ? -1 : id2+pivot+1 : id1;
    }
private:  
    int findPivot(vector<int>& nums, int l, int r) {
        if (l == r) return l;
        
        int mid = (l+r)/2;
        
        printf("%d\t%d\t%d\n",l,mid,r);

        if (nums[mid] > nums[l]) return findPivot(nums, mid, r);
        else return findPivot(nums, l, mid);
    }
    
    int bs(vector<int>& nums, int l, int r, int val) {
        
    }
};

int main() {
    vector<int> nums({4,5,6,7,0,1,2});
    int val = 3;

    cout << Solution().search(nums, val) << endl;

    return 0;
}