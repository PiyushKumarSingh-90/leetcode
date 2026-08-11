import java.util.*;

class Solution {
    public String removeDuplicateLetters(String s) {

        int[] last = new int[26];

        // Store last position
        for (int i = 0; i < s.length(); i++) {
            last[s.charAt(i) - 'a'] = i;
        }

        Stack<Character> stack = new Stack<>();
        boolean[] used = new boolean[26];

        for (int i = 0; i < s.length(); i++) {

            char ch = s.charAt(i);
            int index = ch - 'a';

            // Already present
            if (used[index]) {
                continue;
            }

            // Remove bigger characters
            // only if they appear again later
            while (
                !stack.isEmpty() &&
                stack.peek() > ch &&
                last[stack.peek() - 'a'] > i
            ) {
                char removed = stack.pop();
                used[removed - 'a'] = false;
            }

            stack.push(ch);
            used[index] = true;
        }

        StringBuilder ans = new StringBuilder();

        for (char ch : stack) {
            ans.append(ch);
        }

        return ans.toString();
    }
}