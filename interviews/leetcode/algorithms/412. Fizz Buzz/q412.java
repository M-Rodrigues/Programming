class Solution {
    public List<String> fizzBuzz(int n) {
        ArrayList<String> ans = new ArrayList<>(n);
        
        for (int i = 1; i <= n; i++) {
            String s;
            if (i%3 == 0 && i%5 == 0) {
                s = "FizzBuzz";
            } else if (i%3 == 0) {
                s = "Fizz";
            } else if (i%5 == 0) {
                s = "Buzz";
            } else {
                s = "" + i + "";
            }
            
            ans.add(s);
        }
        return ans;
    }
}