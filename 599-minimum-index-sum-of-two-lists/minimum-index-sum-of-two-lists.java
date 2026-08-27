import java.util.*;

class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {

        HashMap<String, Integer> index = new HashMap<>();

        for (int i = 0; i < list1.length; i++) {
            index.put(list1[i], i);
        }

        List<String> ans = new ArrayList<>();

        int minimum = Integer.MAX_VALUE;

        for (int j = 0; j < list2.length; j++) {

            String word = list2[j];

            if (index.containsKey(word)) {

                int total = index.get(word) + j;

                if (total < minimum) {

                    minimum = total;

                    ans.clear();
                    ans.add(word);
                }
                else if (total == minimum) {

                    ans.add(word);
                }
            }
        }

        return ans.toArray(new String[0]);
    }
}