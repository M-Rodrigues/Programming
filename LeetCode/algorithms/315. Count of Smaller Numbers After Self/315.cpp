#include<bits/stdc++.h>
using namespace std;

class Solution {
    int INF = 10000000;
    map<int, int> inv;
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size());
        
        for (int i = nums.size()-1; i >= 0; i--) {
            int cnt = 0;
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] > nums[j]) cnt++;
            }
            ans[i] = cnt;
        }
        
        return ans;
    }

    vector<int> countSmaller2(vector<int>& nums) {
        vector<int> ans(nums.size());
        inv.clear();

        countMerge(nums);

        for (int i = 0; i < nums.size(); i++)
            ans[i] = inv[nums[i]];
        
        return ans;
    }

    void countMerge(vector<int>& arr) {
        vector<int> u1, u2;

        if (arr.size() == 1) return;

        for (int i = 0; i < arr.size()/2; i++)
            u1.push_back(arr[i]);
        for (int i = arr.size()/2; i < arr.size(); i++)
            u2.push_back(arr[i]);

        mergeSort(u1);
        mergeSort(u2);

        u1.push_back(INF);
        u2.push_back(INF);

        int i1 = 0, i2 = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (u1[i1] <= u2[i2]) {
                arr[i] = u1[i1]; i1++;
                inv[u2[i2]]++;
            } else {
                arr[i] = u2[i2]; i2++;
                // inv+= u1.size()-i1-1;
                inv[u1[i1]]++;
            }
        }       
    }

    int mergeSort(vector<int>& arr) {
        int inv = 0;
        vector<int> u1, u2;

        if (arr.size() == 1) return 0;

        for (int i = 0; i < arr.size()/2; i++)
            u1.push_back(arr[i]);
        for (int i = arr.size()/2; i < arr.size(); i++)
            u2.push_back(arr[i]);

        inv+=mergeSort(u1);
        inv+=mergeSort(u2);

        u1.push_back(INF);
        u2.push_back(INF);

        int i1 = 0, i2 = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (u1[i1] <= u2[i2]) {
                arr[i] = u1[i1]; i1++;
            } else {
                arr[i] = u2[i2]; i2++;
                inv+= u1.size()-i1-1;
            }
        }       

        return inv;
    }
};

int main () {
    Solution q;
    vector<int> input = {5,2,6,1};
    
    vector<int> ans(q.countSmaller(input));
    for (int x : ans) printf("%d ",x);
    printf("\n");

    vector<int> arr(q.countSmaller2(input));
    for (int x : arr) printf("%d ",x);
    printf("\n");

    return 0;
}