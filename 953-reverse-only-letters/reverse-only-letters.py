class Solution:
    def reverseOnlyLetters(self, s):
        arr = list(s)

        left = 0
        right = len(arr) - 1

        while left < right:

            if not arr[left].isalpha():
                left += 1
                continue

            if not arr[right].isalpha():
                right -= 1
                continue

            arr[left], arr[right] = arr[right], arr[left]

            left += 1
            right -= 1

        return "".join(arr)