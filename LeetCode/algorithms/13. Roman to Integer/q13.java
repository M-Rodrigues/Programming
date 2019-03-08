class Solution {
    public int romanToInt(String s) {
        int i = 0;
        int N = s.length();
        int ans = 0;
        while (i < N){
            if (s.charAt(i) == 'I') {
                if (i+1 < N && s.charAt(i+1) == 'V') {
                    ans += 4;
                    i += 2;
                } else if (i+1 < N && s.charAt(i+1) == 'X') {
                    ans += 9;
                    i += 2;
                } else if (i+1 < N && s.charAt(i+1) == 'I') {
                    if (i+2 < N && s.charAt(i+2) == 'I') {
                        ans += 3;
                        i += 3;
                    } else {
                        ans += 2;
                        i += 2;
                    }
                } else {
                    ans += 1;
                    i += 1;
                }
            } else if (s.charAt(i) == 'X') {
                if (i+1 < N && s.charAt(i+1) == 'L') {
                    ans += 40;
                    i += 2;
                } else if (i+1 < N && s.charAt(i+1) == 'C') {
                    ans += 90;
                    i += 2;
                } else if (i+1 < N && s.charAt(i+1) == 'X') {
                    if (i+2 < N && s.charAt(i+2) == 'X') {
                        ans += 30;
                        i += 3;
                    } else {
                        ans += 20;
                        i += 2;
                    }
                } else {
                    ans += 10;
                    i += 1;
                }
            } else if (s.charAt(i) == 'C') {
                if (i+1 < N && s.charAt(i+1) == 'D') {
                    ans += 400;
                    i += 2;
                } else if (i+1 < N && s.charAt(i+1) == 'M') {
                    ans += 900;
                    i += 2;
                } else if (i+1 < N && s.charAt(i+1) == 'C') {
                    if (i+2 < N && s.charAt(i+2) == 'C') {
                        ans += 300;
                        i += 3;
                    } else {
                        ans += 200;
                        i += 2;
                    }
                } else {
                    ans += 100;
                    i += 1;
                }
            } else if (s.charAt(i) == 'V') {
                ans += 5; i++;
            } else if (s.charAt(i) == 'L') {
                ans += 50; i++;
            } else if (s.charAt(i) == 'D') {
                ans += 500; i++;
            } else if (s.charAt(i) == 'M') {
                ans += 1000; i++;
            }
        }
        
        return ans;
    }
}