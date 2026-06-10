package Arrays;
public class Two_Sum {

    public int[] twoSum(int[] nums, int target) {
        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if ((nums[i] + nums[j]) == target) {
                    return new int[]{i, j};
                }
            }
        }
        return new int[]{};
    }

    public static void main(String[] args) {
        Two_Sum sol = new Two_Sum();

        int[] nums = {2, 7, 11, 15};
        int target = 9;

        int[] result = sol.twoSum(nums, target);

        System.out.print("Indices: ");
        for (int index : result) {
            System.out.print(index + " ");
        }
    }
}