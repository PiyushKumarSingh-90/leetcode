class Solution:
    def toHex(self, num: int) -> str:
        if num == 0:
            return "0"

        # Convert negative number to 32-bit two's complement
        if num < 0:
            num += 1 << 32

        digits = "0123456789abcdef"
        ans = []

        while num > 0:
            remainder = num % 16
            ans.append(digits[remainder])
            num //= 16

        return ''.join(ans[::-1])