/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseEvenLengthGroups(ListNode head) {

        ListNode dummy = new ListNode(0, head);
        ListNode prev = dummy;

        int group = 1;

        while (prev.next != null) {

            ListNode end = prev;
            int count = 0;

            // Find actual size of current group
            while (count < group && end.next != null) {
                end = end.next;
                count++;
            }

            ListNode nextGroup = end.next;

            // Reverse if actual group size is even
            if (count % 2 == 0) {

                ListNode curr = prev.next;
                ListNode tail = curr;
                ListNode reversePrev = nextGroup;

                for (int i = 0; i < count; i++) {
                    ListNode next = curr.next;

                    curr.next = reversePrev;
                    reversePrev = curr;
                    curr = next;
                }

                prev.next = reversePrev;
                prev = tail;

            } else {

                for (int i = 0; i < count; i++) {
                    prev = prev.next;
                }
            }

            group++;
        }

        return dummy.next;
    }
}