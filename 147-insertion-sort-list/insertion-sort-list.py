class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:

        if not head or not head.next:
            return head

        dummy = ListNode(0)
        curr = head

        while curr:

            nxt = curr.next
            prev = dummy

            while prev.next and prev.next.val < curr.val:
                prev = prev.next

            curr.next = prev.next
            prev.next = curr

            curr = nxt

        return dummy.next