class Solution:
    def countCharacters(self, words, chars):
        freq = {}

        for ch in chars:
            freq[ch] = freq.get(ch, 0) + 1

        total = 0

        for word in words:
            current = freq.copy()
            good = True

            for ch in word:

                if current.get(ch, 0) == 0:
                    good = False
                    break

                current[ch] -= 1

            if good:
                total += len(word)

        return total