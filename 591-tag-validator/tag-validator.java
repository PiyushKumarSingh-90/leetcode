import java.util.*;

class Solution {

    public boolean isValid(String code) {

        Stack<String> stack = new Stack<>();

        int i = 0;
        int n = code.length();

        while (i < n) {

            // Root already closed but more content remains
            if (i > 0 && stack.isEmpty()) {
                return false;
            }

            // CDATA
            if (code.startsWith("<![CDATA[", i)) {

                if (stack.isEmpty()) {
                    return false;
                }

                int j = code.indexOf("]]>", i + 9);

                if (j == -1) {
                    return false;
                }

                i = j + 3;
            }

            // Closing tag
            else if (code.startsWith("</", i)) {

                int j = code.indexOf('>', i + 2);

                if (j == -1) {
                    return false;
                }

                String tag = code.substring(i + 2, j);

                if (!validTag(tag)) {
                    return false;
                }

                if (stack.isEmpty() ||
                    !stack.peek().equals(tag)) {
                    return false;
                }

                stack.pop();

                i = j + 1;
            }

            // Opening tag
            else if (code.charAt(i) == '<') {

                int j = code.indexOf('>', i + 1);

                if (j == -1) {
                    return false;
                }

                String tag = code.substring(i + 1, j);

                if (!validTag(tag)) {
                    return false;
                }

                stack.push(tag);

                i = j + 1;
            }

            // Normal text
            else {

                if (stack.isEmpty()) {
                    return false;
                }

                i++;
            }
        }

        return stack.isEmpty();
    }


    private boolean validTag(String tag) {

        if (tag.length() < 1 || tag.length() > 9) {
            return false;
        }

        for (char ch : tag.toCharArray()) {

            if (ch < 'A' || ch > 'Z') {
                return false;
            }
        }

        return true;
    }
}