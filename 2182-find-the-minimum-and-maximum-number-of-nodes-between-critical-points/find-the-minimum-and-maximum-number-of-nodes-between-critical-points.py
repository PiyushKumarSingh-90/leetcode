# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head):
        first = -1
        prev_critical = -1

        min_dist = float('inf')
        max_dist = -1

        prev = head
        curr = head.next
        index = 1

        while curr and curr.next:
            nxt = curr.next

            is_critical = (
                (curr.val > prev.val and curr.val > nxt.val) or
                (curr.val < prev.val and curr.val < nxt.val)
            )

            if is_critical:
                if first == -1:
                    first = index
                else:
                    min_dist = min(min_dist, index - prev_critical)
                    max_dist = index - first

                prev_critical = index

            prev = curr
            curr = curr.next
            index += 1

        if max_dist == -1:
            return [-1, -1]

        return [min_dist, max_dist]