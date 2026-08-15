class Solution:
    def nextGreaterElement(self, nums1, nums2):
        ans = []

        for num in nums1:
            index = nums2.index(num)
            greater = -1

            for j in range(index + 1, len(nums2)):
                if nums2[j] > num:
                    greater = nums2[j]
                    break

            ans.append(greater)

        return ans