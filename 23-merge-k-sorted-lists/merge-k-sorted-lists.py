import heapq

class Solution:
    def mergeKLists(self, lists):

        heap = []

        # Add the first node of every list
        for i, node in enumerate(lists):
            if node:
                heapq.heappush(heap, (node.val, i, node))

        dummy = ListNode(-1)
        curr = dummy

        while heap:

            val, i, node = heapq.heappop(heap)

            curr.next = node
            curr = curr.next

            if node.next:
                heapq.heappush(heap, (node.next.val, i, node.next))

        return dummy.next