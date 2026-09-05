class Solution {
    public int minimumSwaps(int[] nums) {

        int zeros = 0;

        for (int num : nums) {
            if (num == 0) {
                zeros++;
            }
        }

        int nonZeros = nums.length - zeros;

        int swaps = 0;

        for (int i = 0; i < nonZeros; i++) {
            if (nums[i] == 0) {
                swaps++;
            }
        }

        return swaps;
    }
}