public class q1 {
    public static int insertion(int N, int M, int i, int j) {
        M = M << i;
        int msk = (-1 << (j+1)) | ~(-1 << i);
        return (N & msk) | M;
    }


    public static int BinToInt(String s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1') ans += 1 << (s.length()-1-i);
        }
        return ans;
    }
    
    public static void main(String[] args) {
        System.out.println(
                Integer.toBinaryString(
                    insertion(BinToInt("10000000000"), 
                    BinToInt("10011"), 
                    2, 
                    6)));
    }
}