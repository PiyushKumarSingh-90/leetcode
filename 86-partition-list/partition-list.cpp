/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) 
    {
         ListNode* beforeHead = new ListNode(0); // Dummy head for < x
        ListNode* afterHead = new ListNode(0);  // Dummy head for >= x
        ListNode* before = beforeHead;
        ListNode* after = afterHead;

        while (head) {
            if (head->val < x) {
                before->next = head;
                before = before->next;
            } else {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }

        after->next = nullptr; // Mark end of after list
        before->next = afterHead->next; // Connect before list to after list

        return beforeHead->next;
    }
};