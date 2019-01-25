public class q2 {
    public static void BinaryToString(double n) {
        StringBuilder ans = new StringBuilder();

        while (Double.compare(n, 0) != 0 || ans.length() == 32) {
            n *= 2;

            if (n > 1 || Double.compare(n, 1) == 0) {
                ans.append('1');
                n -= 1.0;
            } else {
                ans.append('0');
            }
        }

        if (Double.compare(n, 0) != 0 && ans.length() == 32) {
            System.out.println("ERROR.");
        } else {
            System.out.println(ans.toString());
        }
    }
    
    public static void main(String[] args) {
        BinaryToString(0.11);
    }
}