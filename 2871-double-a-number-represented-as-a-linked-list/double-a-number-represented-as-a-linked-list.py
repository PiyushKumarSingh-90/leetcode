class Solution:
    def doubleIt(self, head):

        # If first digit creates a carry
        if head.val > 4:
            head = ListNode(0, head)

        curr = head

        while curr:
            curr.val = (curr.val * 2) % 10

            # Carry from the next digit
            if curr.next and curr.next.val > 4:
                curr.val += 1

            curr = curr.next

        return head