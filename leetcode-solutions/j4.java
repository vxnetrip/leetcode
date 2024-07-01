import java.util.ArrayList;

public class j4 {
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {

        int i = 0;
        int j = 0;

        ArrayList<Integer> arr = new ArrayList<>();

        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] < nums2[j]) {
                arr.add(nums1[i]);
                i++;
            } else {
                arr.add(nums2[j]);
                j++;
            }
        }

        while (i < nums1.length) {
            arr.add(nums1[i]);
            i++;
        }

        while (j < nums2.length) {
            arr.add(nums2[j]);
            j++;
        }

        for (int k = 0; k < arr.size(); k++) {
            System.out.println(arr.get(k));
        }

        int medianIndex = arr.size() / 2;
        double median;

        if (arr.size() % 2 != 0) {
            median = arr.get(medianIndex);
            return median;
        } else {
            median = (arr.get(medianIndex) + arr.get(medianIndex - 1)) / 2.0;
            return median;
        }
    }

    public static void main(String[] args) {
        System.out.println("4. Median of wo sorted arrays");
        int[] nums1 = { 1, 3, 4 };
        int[] nums2 = { 2 };
        double result = findMedianSortedArrays(nums1, nums2);

        System.out.println(result);
    }
}
