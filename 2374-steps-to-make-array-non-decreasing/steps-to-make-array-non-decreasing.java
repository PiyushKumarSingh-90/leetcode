import java.util.*;

class Solution {
    public int totalSteps(int[] nums) {

        Stack<int[]> stack = new Stack<>();
        int ans = 0;

        for (int num : nums) {

            int steps = 0;

            while (!stack.isEmpty() && num >= stack.peek()[0]) {
                steps = Math.max(steps, stack.peek()[1]);
                stack.pop();
            }

            if (!stack.isEmpty()) {
                steps++;
            } else {
                steps = 0;
            }

            ans = Math.max(ans, steps);

            stack.push(new int[]{num, steps});
        }

        return ans;
    }
}