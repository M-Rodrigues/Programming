import java.util.Map;

public class q771 {
    public static int numJewelsInStones(String J, String S) {
        Map<Character, Integer> map = new HashMap<>();
        
        for (int i = 0; i < J.length(); i++) {
            map.put(J.charAt(i), 0);
        }

        int count = 0;
        for (int i = 0; i < S.length(); i++) {
            if (map.containsKey(S.charAt(i))) count++;
        }
        
        return count;
    }

    public static void main(String[] args) {
        String J = "aA";
        String S = "aAAbbbb";
        System.out.println(numJewelsInStones(J,S));
    }
}