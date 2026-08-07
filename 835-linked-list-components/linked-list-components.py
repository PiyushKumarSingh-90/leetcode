# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def numComponents(self, head: Optional[ListNode], nums: List[int]) -> int:
        s = set(nums)
        ans = 0

        while head:
            if head.val in s and (head.next is None or head.next.val not in s):
                ans += 1
            head = head.next

        return ans