# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNodes(self, head):

        # Reverse the linked list
        prev = None
        curr = head

        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt

        # Remove smaller nodes
        max_val = prev.val
        curr = prev

        while curr and curr.next:
            if curr.next.val < max_val:
                curr.next = curr.next.next
            else:
                curr = curr.next
                max_val = curr.val

        # Reverse again
        head = None
        curr = prev

        while curr:
            nxt = curr.next
            curr.next = head
            head = curr
            curr = nxt

        return head
        