class Solution {
    public boolean isMiddleElementUnique(int[] nums) {

        int mid = nums.length / 2;
        int target = nums[mid];

        int count = 0;

        for (int num : nums) {

            if (num == target) {
                count++;

                if (count > 1) {
                    return false;
                }
            }
        }

        return true;
    }
}