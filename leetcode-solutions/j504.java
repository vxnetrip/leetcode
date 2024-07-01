
/**
 * j504
 */

public class j504 {

    public static String reverseString(String str) {
        StringBuilder reversedStr = new StringBuilder(str);
        int len = str.length();
        for (int i = 0; i < len / 2; i++) {
            char temp = reversedStr.charAt(i);
            reversedStr.setCharAt(i, reversedStr.charAt(len - i - 1));
            reversedStr.setCharAt(len - i - 1, temp);
        }

        return reversedStr.toString();
    }

    public static String convertToBase7(int num) {

        if (num == 0) {
            return "0";
        }

        int n = num;

        boolean isNegative = false;

        if (n < 0) {
            isNegative = true;
            n = n * -1;
        }

        String pre_result = "";

        while (n > 0) {
            int remainder = n % 7;
            pre_result += String.valueOf(remainder);
            n /= 7;
        }

        String result = reverseString(pre_result);
        if (isNegative) {
            return '-' + result;
        } else {
            return result;
        }
    }

    public static void main(String args[]) {
        int num = -100;
        String result = convertToBase7(num);
        System.out.println(result);
    }
}