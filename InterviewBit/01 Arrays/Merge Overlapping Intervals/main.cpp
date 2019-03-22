/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if (A.size() <= 1) return A;
    
    sort(A.begin(), A.end(), [](const Interval &i1, const Interval &i2) {
        if (i1.start == i2.start) return i1.end <= i2.end;
        return i1.start <= i2.start;
    });
    
    vector<Interval> ans;
    ans.push_back(A[0]);
    
    for (int i = 0; i < A.size(); i++) {
        Interval &i1 = ans[ans.size()-1], &i2 = A[i];
        
        if (i2.start <= i1. end) { // overlap
            Interval inter(i1.start, max(i1.end, i2.end));
            
            ans.pop_back();
            ans.push_back(inter);
        } else {
            ans.push_back(i2);
        }
    }
    
    return ans;
}
