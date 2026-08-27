class Solution:
    def shortestCompletingWord(self, licensePlate: str, words):
        required = {}

        for ch in licensePlate:
            if ch.isalpha():
                ch = ch.lower()
                required[ch] = required.get(ch, 0) + 1

        ans = None

        for word in words:
            count = {}

            for ch in word:
                count[ch] = count.get(ch, 0) + 1

            valid = True

            for ch in required:
                if count.get(ch, 0) < required[ch]:
                    valid = False
                    break

            if valid and (ans is None or len(word) < len(ans)):
                ans = word

        return ans