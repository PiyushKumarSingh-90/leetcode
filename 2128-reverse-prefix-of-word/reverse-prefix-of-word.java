class Solution {
    public String reversePrefix(String word, char ch) {

        int index = word.indexOf(ch);

        if (index == -1) {
            return word;
        }

        StringBuilder prefix =
            new StringBuilder(word.substring(0, index + 1));

        prefix.reverse();

        return prefix.toString() + word.substring(index + 1);
    }
}