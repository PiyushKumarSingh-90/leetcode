import java.util.PriorityQueue;

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {

        PriorityQueue<ListNode> pq = new PriorityQueue<>((a, b) -> a.val - b.val);

        // Put the first node of every list into the heap
        for (ListNode node : lists) {
            if (node != null) {
                pq.add(node);
            }
        }

        ListNode dummy = new ListNode(-1);
        ListNode curr = dummy;

        while (!pq.isEmpty()) {

            ListNode temp = pq.poll(); // Smallest node

            curr.next = temp;
            curr = curr.next;

            if (temp.next != null) {
                pq.add(temp.next);
            }
        }

        return dummy.next;
    }
}