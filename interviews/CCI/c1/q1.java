import java.util.Arrays;

import java.util.HashMap;

public class q1 {
    public static void main(String[] args) {
        String s = "Olá Mundos!";
        System.out.println(isUnique(s));
        System.out.println(isUnique2(s));
        System.out.println(isUnique3(s));
    }

    // Usando HashMap
    public static boolean isUnique(String s) {
        HashMap<Character, Integer> m = new HashMap<Character, Integer>();
        for (int i = 0; i < s.length(); i++) {
            if (m.containsKey(s.charAt(i))) return false;
            m.put(s.charAt(i),0);            
        }
        return true;
    }

    // Ordenando a string
    public static boolean isUnique2(String s) {
        char[] arr = s.toCharArray();
        Arrays.sort(arr);
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] == arr[i-1]) return false;
        }
        return true;
    }

    // Sem ordenar a string
    public static boolean isUnique3(String s) {
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j < s.length(); j++) {
                if (s.charAt(i) == s.charAt(j)) return false;
            }
        }
        return true;
    } 

}