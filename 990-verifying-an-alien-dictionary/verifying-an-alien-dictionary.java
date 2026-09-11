class Solution {
    public boolean isAlienSorted(String[] words, String order) {

        int[] rank = new int[26];

        for (int i = 0; i < order.length(); i++) {
            rank[order.charAt(i) - 'a'] = i;
        }

        for (int i = 0; i < words.length - 1; i++) {

            String first = words[i];
            String second = words[i + 1];

            boolean same = true;

            int length = Math.min(
                first.length(),
                second.length()
            );

            for (int j = 0; j < length; j++) {

                if (first.charAt(j) != second.charAt(j)) {

                    same = false;

                    if (
                        rank[first.charAt(j) - 'a'] >
                        rank[second.charAt(j) - 'a']
                    ) {
                        return false;
                    }

                    break;
                }
            }

            if (same && first.length() > second.length()) {
                return false;
            }
        }

        return true;
    }
}