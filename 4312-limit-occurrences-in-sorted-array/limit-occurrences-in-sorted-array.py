class Solution:
    def limitOccurrences(self, nums, k):
        freq = {}
        ans = []

        for num in nums:
            freq[num] = freq.get(num, 0) + 1

            if freq[num] <= k:
                ans.append(num)

        return ans