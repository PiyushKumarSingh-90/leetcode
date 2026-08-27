class Solution:
    def findRestaurant(self, list1, list2):
        index = {}

        for i in range(len(list1)):
            index[list1[i]] = i

        ans = []
        minimum = float("inf")

        for j in range(len(list2)):

            word = list2[j]

            if word in index:
                total = index[word] + j

                if total < minimum:
                    minimum = total
                    ans = [word]

                elif total == minimum:
                    ans.append(word)

        return ans