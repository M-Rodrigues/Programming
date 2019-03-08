public class q326 {
    public static void main(String[] args) {
        Long n = 1L;
        for (int i = 0; i < 15; i++) {
            System.out.println(n + ": " + Long.toBinaryString(n) + " :: " + Long.toString(n, 3));
            n *= 3;
        }
    }
}