class Solution {
    public int countCharacters(String[] words, String chars) {

        int[] available = new int[26];

        for (char ch : chars.toCharArray()) {
            available[ch - 'a']++;
        }

        int ans = 0;

        for (String word : words) {

            int[] current = available.clone();
            boolean good = true;

            for (char ch : word.toCharArray()) {

                current[ch - 'a']--;

                if (current[ch - 'a'] < 0) {
                    good = false;
                    break;
                }
            }

            if (good) {
                ans += word.length();
            }
        }

        return ans;
    }
}