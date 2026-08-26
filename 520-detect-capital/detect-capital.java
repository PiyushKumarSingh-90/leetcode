class Solution {
    public boolean detectCapitalUse(String word) {

        int capital = 0;

        for (char ch : word.toCharArray()) {

            if (Character.isUpperCase(ch)) {
                capital++;
            }
        }

        if (capital == word.length()) {
            return true;
        }

        if (capital == 0) {
            return true;
        }

        if (capital == 1 &&
            Character.isUpperCase(word.charAt(0))) {
            return true;
        }

        return false;
    }
}