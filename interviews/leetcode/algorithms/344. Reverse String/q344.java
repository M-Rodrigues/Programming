class Solution {
    public String reverseString(String s) {
        char[] arr = s.toCharArray();
        for (int i = 0; i < arr.length/2; i++) {
            char c = arr[i];
            arr[i] = arr[arr.length-i-1];
            arr[arr.length-i-1] = c;
        }
        return String.valueOf(arr);
    }
}