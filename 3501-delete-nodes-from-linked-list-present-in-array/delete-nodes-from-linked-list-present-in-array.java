class Solution {
    public ListNode modifiedList(int[] nums, ListNode head) {

        HashSet<Integer> remove = new HashSet<>();

        for (int x : nums) {
            remove.add(x);
        }

        // Remove nodes from the beginning
        while (head != null && remove.contains(head.val)) {
            head = head.next;
        }

        ListNode curr = head;

        // Remove remaining nodes
        while (curr != null && curr.next != null) {

            if (remove.contains(curr.next.val)) {
                curr.next = curr.next.next;
            } else {
                curr = curr.next;
            }
        }

        return head;
    }
}