class Solution {
    public int minimumPairRemoval(int[] nums) {
        ArrayList<Integer> list = new ArrayList<>();

        for (int x : nums) {
            list.add(x);
        }

        int count = 0;

        while (!isSorted(list)) {

            // Find minimum adjacent pair
            int index = 0;

            for (int i = 1; i < list.size() - 1; i++) {
                if (list.get(i) + list.get(i + 1)
                        < list.get(index) + list.get(index + 1)) {
                    index = i;
                }
            }

            // Merge the pair
            int sum = list.get(index) + list.get(index + 1);

            list.set(index, sum);
            list.remove(index + 1);

            count++;
        }

        return count;
    }

    private boolean isSorted(ArrayList<Integer> list) {
        for (int i = 1; i < list.size(); i++) {
            if (list.get(i - 1) > list.get(i)) {
                return false;
            }
        }

        return true;
    }
}