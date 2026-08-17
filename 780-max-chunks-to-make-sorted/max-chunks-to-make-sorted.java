class Solution {
    public int maxChunksToSorted(int[] arr) {

        int maximum = 0;
        int chunks = 0;

        for (int i = 0; i < arr.length; i++) {

            maximum = Math.max(maximum, arr[i]);

            if (maximum == i) {
                chunks++;
            }
        }

        return chunks;
    }
}