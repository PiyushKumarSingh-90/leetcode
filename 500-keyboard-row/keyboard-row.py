class Solution:
    def findWords(self, words):
        row1 = set("qwertyuiop")
        row2 = set("asdfghjkl")
        row3 = set("zxcvbnm")

        ans = []

        for word in words:
            if (
                all(ch.lower() in row1 for ch in word)
                or all(ch.lower() in row2 for ch in word)
                or all(ch.lower() in row3 for ch in word)
            ):
                ans.append(word)

        return ans