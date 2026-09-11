class Solution {
    public boolean validUtf8(int[] data) {

        int remaining = 0;

        for (int b : data) {

            if (remaining == 0) {

                int mask = 128;
                int count = 0;

                while ((b & mask) != 0) {
                    count++;
                    mask >>= 1;
                }

                if (count == 0) {
                    continue;
                }

                if (count == 1 || count > 4) {
                    return false;
                }

                remaining = count - 1;
            }

            else {

                if ((b >> 6) != 2) {
                    return false;
                }

                remaining--;
            }
        }

        return remaining == 0;
    }
}