class Solution:
    def isPalindrome(self, x: int) -> bool:

        original = x
        rev = 0

        while x > 0:
            digit = x % 10
            rev = rev * 10 + digit
            x = x // 10

        if original == rev:
            return True
        else:
            return False