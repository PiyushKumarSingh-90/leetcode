/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *     // Constructor initializes an empty nested list.
 *     public NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     public NestedInteger(int value);
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public void add(NestedInteger ni);
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return empty list if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
 
import java.util.*;

class Solution {
    public NestedInteger deserialize(String s) {

        // Single integer
        if (s.charAt(0) != '[') {
            return new NestedInteger(Integer.parseInt(s));
        }

        Stack<NestedInteger> stack = new Stack<>();

        int num = 0;
        int sign = 1;
        boolean hasNum = false;

        for (char ch : s.toCharArray()) {

            if (ch == '[') {

                stack.push(new NestedInteger());

            } else if (ch == '-') {

                sign = -1;

            } else if (Character.isDigit(ch)) {

                num = num * 10 + (ch - '0');
                hasNum = true;

            } else if (ch == ',') {

                if (hasNum) {
                    stack.peek().add(
                        new NestedInteger(sign * num)
                    );
                }

                num = 0;
                sign = 1;
                hasNum = false;

            } else if (ch == ']') {

                if (hasNum) {
                    stack.peek().add(
                        new NestedInteger(sign * num)
                    );
                }

                num = 0;
                sign = 1;
                hasNum = false;

                NestedInteger completed = stack.pop();

                if (!stack.isEmpty()) {
                    stack.peek().add(completed);
                } else {
                    return completed;
                }
            }
        }

        return null;
    }
}