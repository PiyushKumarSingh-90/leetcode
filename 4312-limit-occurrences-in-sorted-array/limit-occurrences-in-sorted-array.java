import java.util.*;

class Solution {
    public int[] limitOccurrences(int[] nums, int k) {

        int write = 0;

        for (int num : nums) {

            if (write < k || num != nums[write - k]) {
                nums[write] = num;
                write++;
            }
        }

        return Arrays.copyOf(nums, write);
    }
}