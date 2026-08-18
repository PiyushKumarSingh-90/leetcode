import java.util.*;

class Solution {
    public int[] finalPrices(int[] prices) {

        int[] ans = prices.clone();

        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < prices.length; i++) {

            while (!stack.isEmpty() &&
                   prices[stack.peek()] >= prices[i]) {

                int index = stack.pop();

                ans[index] = prices[index] - prices[i];
            }

            stack.push(i);
        }

        return ans;
    }
}