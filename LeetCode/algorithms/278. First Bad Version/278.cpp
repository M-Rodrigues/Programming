// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return lb(1, n);
    }
private:
    int lb(int l, int r) {
        if (l == r) return l;
        
        int mid = l/2+r/2;
        if (l%2 == 1 and r%2 == 1) mid++;
        
        if (isBadVersion(mid)) return lb(l, mid);
        else return lb(mid+1, r);
    }
};