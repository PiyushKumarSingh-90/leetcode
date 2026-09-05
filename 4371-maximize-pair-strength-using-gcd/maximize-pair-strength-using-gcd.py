class Solution:
    def maxPairStrength(self, nums):

        def gcd(a, b):
            while b != 0:
                a, b = b, a % b

            return a

        ans = 0

        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):

                g = gcd(nums[i], nums[j])

                strength = (
                    nums[i] * nums[j]
                ) // (g * g)

                ans = max(ans, strength)

        return ans