public class q3 {
    public static void main(String[] args) {
        
        String s = "Mr John Smith    ";    
        System.out.println(URLfy(s.toCharArray()));        
    }

    public static char[] URLfy(char[] arr) {
        int i = arr.length-1;
        int j = arr.length-1;
        while(arr[i] == ' ') i--;
        
        while (i > 0) {
            if (arr[i] != ' ') {
                arr[j] = arr[i]; i--; j--;
            } else {
                i--;
                arr[j] = '0'; j--;
                arr[j] = '2'; j--;
                arr[j] = '%'; j--;
            }
        }
        
        return arr;
    }
}