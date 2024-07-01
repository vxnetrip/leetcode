public class j2490 {

    public static boolean isCircularSentence(String sentence) {

        String[] ss = sentence.split(" ");

        if (ss.length == 1) {
            return ss[0].charAt(0) == ss[0].charAt(ss[0].length() - 1);
        }

        for (int i = 0; i < ss.length - 1; i++) {
            char c1 = ss[i].charAt(ss[i].length() - 1);
            char c2 = ss[i + 1].charAt(0);
            if (c1 != c2) {
                return false;
            }
        }

        char lastChar = ss[ss.length - 1].charAt(ss[ss.length - 1].length() - 1);
        char firstChar = ss[0].charAt(0);

        return lastChar == firstChar;
    }

    public static void main(String[] args) {
        String sentence = "Zaraz zejdzie Edward dalej";
        boolean result = isCircularSentence(sentence);
        System.out.println(result);
    }
}
