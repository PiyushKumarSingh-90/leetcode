class Solution:
    def uncommonFromSentences(self, s1, s2):
        freq = {}

        for word in s1.split() + s2.split():
            freq[word] = freq.get(word, 0) + 1

        ans = []

        for word in freq:
            if freq[word] == 1:
                ans.append(word)

        return ans