class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0:
            return "0"

        negative = num < 0
        num = abs(num)

        ans = []

        while num > 0:
            remainder = num % 7
            ans.append(str(remainder))

            num //= 7

        if negative:
            ans.append("-")

        return ''.join(ans[::-1])