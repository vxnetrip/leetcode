import java.util.Arrays;
import java.util.HashMap;

/**
 * j1331
 */
public class j1331 {

    public static int[] arrayRankTransform(int[] arr) {
        int[] sortedarr = Arrays.copyOf(arr, arr.length);
        Arrays.sort(sortedarr);

        HashMap<Integer, Integer> rankMap = new HashMap<>();

        int rank = 1;

        for (int num : sortedarr) {
            if (!rankMap.containsKey(num)) {
                rankMap.put(num, rank++);
            }
        }

        for (int i = 0; i < arr.length; i++) {
            arr[i] = rankMap.get(arr[i]);
        }

        return arr;
    }

    public static void main(String[] args) {
        int arr[] = { 40, 10, 20, 30 };
        int[] result = arrayRankTransform(arr);

        for (int i = 0; i < result.length; i++) {
            System.out.println(result[i]);
        }
    }
}