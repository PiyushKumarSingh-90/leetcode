class Solution {
    public String removeOuterParentheses(String s) {

        int depth = 0;

        StringBuilder ans = new StringBuilder();

        for (char ch : s.toCharArray()) {

            if (ch == '(') {

                if (depth > 0) {
                    ans.append(ch);
                }

                depth++;

            } else {

                depth--;

                if (depth > 0) {
                    ans.append(ch);
                }
            }
        }

        return ans.toString();
    }
}