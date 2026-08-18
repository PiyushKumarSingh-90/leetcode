import java.util.*;

class Solution {
    public String makeGood(String s) {

        Stack<Character> stack = new Stack<>();

        for (char ch : s.toCharArray()) {

            if (!stack.isEmpty() &&
                Character.toLowerCase(stack.peek()) ==
                Character.toLowerCase(ch) &&
                stack.peek() != ch) {

                stack.pop();

            } else {

                stack.push(ch);
            }
        }

        StringBuilder ans = new StringBuilder();

        for (char ch : stack) {
            ans.append(ch);
        }

        return ans.toString();
    }
}