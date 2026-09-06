class Solution:
    def commonChars(self, words):
        freq = {}

        for ch in words[0]:
            freq[ch] = freq.get(ch, 0) + 1

        for word in words[1:]:
            current = {}

            for ch in word:
                current[ch] = current.get(ch, 0) + 1

            for ch in freq:
                freq[ch] = min(
                    freq[ch],
                    current.get(ch, 0)
                )

        ans = []

        for ch in freq:
            for _ in range(freq[ch]):
                ans.append(ch)

        return ans