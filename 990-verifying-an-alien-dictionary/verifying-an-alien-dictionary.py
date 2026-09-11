class Solution:
    def isAlienSorted(self, words, order):
        rank = {}

        for i in range(len(order)):
            rank[order[i]] = i

        for i in range(len(words) - 1):

            first = words[i]
            second = words[i + 1]

            same = True

            for j in range(min(len(first), len(second))):

                if first[j] != second[j]:

                    same = False

                    if rank[first[j]] > rank[second[j]]:
                        return False

                    break

            if same and len(first) > len(second):
                return False

        return True