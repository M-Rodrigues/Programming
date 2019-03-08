import java.util.Arrays;

public class q2 {
    public static void main(String[] args) {
        String s1 = "maca";
        String s2 = "cama";
        
        System.out.println(checkPermutation(s1,s2));
    }

    public static boolean checkPermutation(String s1, String s2) {
        char[] arr1 = s1.toCharArray();
        char[] arr2 = s1.toCharArray();

        Arrays.sort(arr1);
        Arrays.sort(arr2);
        return Arrays.equals(arr1,arr2);
    }
}