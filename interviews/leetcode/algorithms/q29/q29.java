/*
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. 
For the purpose of this problem, assume that your function returns 2^31 − 1 when the division result overflows.
*/

public class q29 {
    public static int div(int num, int den) {
        while (num > (den << 1)) {
            den = den << 1;
        }
        return num - den;
    }

    public static int divide(int num, int den) {
        int mod = num;
        while (mod > (den << 1)) {
            mod = div(mod, den);
        }
        return num;
    } 

    public static void main(String[] args) {
        System.out.println(divide(10,3));
    }
}