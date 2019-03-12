class NumArray {
    vector<int> bit;
    
    void add(int x, int id) {
        while (id < bit.size()) {
            bit[id] += x;
            id += (id & -id);
        }
    }
    
    int query(int id) {
        int sum = 0;
        while (id > 0) {
            sum += bit[id];
            id -= (id & -id);
        }
        return sum;
    }
    
    int get(int n) {
        return query(n) - query(n-1);
    }
public:
    NumArray(vector<int> nums) {
        bit.assign(nums.size()+1,0);
        for (int i = 0; i < nums.size(); i++) {
            add(nums[i],i+1);
        }
    }
    
    void update(int i, int val) {
        int old = get(i+1);
        add(-old,i+1);
        add(val,i+1);
    }
    
    int sumRange(int i, int j) {
        return query(j+1) - query(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */