class Solution:
    def addToArrayForm(self, num, k):
        i = len(num) - 1
        ans = []

        while i >= 0 or k > 0:
            if i >= 0:
                k += num[i]
                i -= 1

            ans.append(k % 10)
            k //= 10

        while i >= 0:
            ans.append(num[i])
            i -= 1

        return ans[::-1]