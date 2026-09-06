class Solution:
    def mostCommonWord(self, paragraph, banned):
        paragraph = paragraph.lower()

        for ch in "!?',;.":
            paragraph = paragraph.replace(ch, " ")

        bannedSet = set(banned)

        freq = {}
        ans = ""
        maxCount = 0

        for word in paragraph.split():

            if word not in bannedSet:
                freq[word] = freq.get(word, 0) + 1

                if freq[word] > maxCount:
                    maxCount = freq[word]
                    ans = word

        return ans