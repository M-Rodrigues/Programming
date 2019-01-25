public class q5 {
    public static void main(String[] args) {
        System.out.println(nOfZeros(25));
    }

    public static int nOfZeros(int n) {
        if (n < 5) return 0;
        if (n%5 != 0) return nOfZeros(n-1);
        return nOfFives(n) + nOfZeros(n-1);
    }

    public static int nOfFives(int n) {
        int cnt = 0;
        while (n >= 5) { n /= 5; cnt++; }
        return cnt;
    }
}