import java.util.Arrays;

public class q151 {
    public static String uniteStrings(String[] arr, String sep) {
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < arr.length; i++) {
            ans.append(arr[i]);
            if (i < arr.length-1) ans.append(sep);
        }
        return ans.toString();
    } 
    
    public static String[] reverseArray(String[] arr) {
        for (int i = 0; i < arr.length/2; i++) {
            String aux = arr[i];
            arr[i] = arr[arr.length-i-1];
            arr[arr.length-i-1] = aux;
        }
        return arr;
    }

    public static String noLeadOrTrailSpaces(String str) {
        int i = 0;
        while (i < str.length() && str.charAt(i) == ' ') i++;

        int j = str.length()-1;
        while (j >= 0 && str.charAt(j) == ' ') j--;

        return j < i ? str : str.substring(i, j+1);
    }

    public static String removeTwoSpaces(String str) {
        StringBuilder ans = new StringBuilder();

        for (int i = 0; i < str.length()-1; i++) {
            if (str.charAt(i) == ' ' && str.charAt(i+1) == ' ') continue;
            ans.append(str.charAt(i));
        }

        if (str.length() > 0 && str.charAt(str.length()-1) != ' ') ans.append(str.charAt(str.length()-1));
        return ans.toString();
    }

    public static String reverseWords(String str) {
        if (str == "") return str;
        
        str = noLeadOrTrailSpaces(str);
        str = removeTwoSpaces(str);
        String arr[] = str.split(" ");
        arr = reverseArray(arr);
        str = uniteStrings(arr," ");
        return str;
    }
    public static void main(String[] args) {
        String str = "   ";
        System.out.println("'" + reverseWords(str) + "'");
    }
}