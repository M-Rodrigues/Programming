public class q8 {
    public static String removeSpaces(String s) {
        int i = 0;
        while (s.charAt(i) == ' ') i++;
        StringBuilder ans = new StringBuilder();
        ans.append(s.toCharArray(), i, s.length()-i);
        return ans.toString();
    }
    
    public static String onlyNumber(String s) {
        StringBuilder ans = new StringBuilder();
        int i = 0;
        int j = 0;
        
        if (s.charAt(i) == '-' || s.charAt(i) == '+') { i++; j++; }

        while (i < s.length() && isNumber(s.charAt(i))) i++;

        ans.append(s.toCharArray(), j, i-j);

        return ans.toString(); 
    }

    public static boolean isNumber(char c) { return getNumber(c) >= 0 && getNumber(c) <= 9; }
    public static int getNumber(char c) { return Character.getNumericValue(c) - Character.getNumericValue('0'); }

    public static long atoi(String s) {
        return atoi(s,s.length()-1);
    }

    public static long atoi(String s, int i) {
        if (i < 0) return 0;
        return getNumber(s.charAt(i)) + 10*atoi(s,i-1);
    }

    public static boolean isValid(String str) {
        str = str.replaceAll(" ", "");
        if (str.length() == 0) return false;

        if ((str.charAt(0) == '-' || str.charAt(0) == '+') && str.length() > 1) {
            return isNumber(str.charAt(1));
        } 

        if (isNumber(str.charAt(0))) return true;

        return false;
    }

    public static String removeZeros(String str) {
        int i = 0;
        while (i < str.length() && getNumber(str.charAt(i)) == 0) i++;

        StringBuilder ans = new StringBuilder();
        ans.append(str.toCharArray(),i,str.length()-i);
        return ans.toString();
    }

    public static int myAtoi(String str) {       
        if (isValid(str)) {
            str = removeSpaces(str);
            
            int signal = str.charAt(0) == '-' ? 1 : 0;
            str = onlyNumber(str);
            str = removeZeros(str);
            
            long num = atoi(str);
            
            num = signal == 1 ? -num : num;
            
            long maxv = (1 << 31) - 1;
            long minv = -(1 << 31);

            if (str.length() > 11) return signal == 1 ? (int) (long) minv : (int) (long) maxv; 
            if (num > maxv) return (int) (long) maxv; 
            if (num < minv) return (int) (long) minv;
            
            return (int) (long) num;
        } else {
            return 0;
        }
    }

    public static void main(String[] args) {
        String s = "-9223372036854775809";
        System.out.println(myAtoi(s));        
    }
}