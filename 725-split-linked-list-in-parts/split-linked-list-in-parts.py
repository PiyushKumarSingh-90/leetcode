# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        # Count nodes
        n = 0
        curr = head
        while curr:
            n += 1
            curr = curr.next

        partSize = n // k
        extra = n % k

        ans = []
        curr = head

        for i in range(k):
            ans.append(curr)

            size = partSize + (1 if i < extra else 0)

            if curr:
                for _ in range(size - 1):
                    curr = curr.next

                nxt = curr.next
                curr.next = None
                curr = nxt

        return ans