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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
     
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // Step 1: Reach node before `left`
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Step 2: Reverse sublist from `left` to `right`
        ListNode* curr = prev->next;
        ListNode* next = nullptr;
        ListNode* prevNode = nullptr;
        
        for (int i = left; i <= right; i++) {
            next = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = next;
        }

        // Step 3: Reconnect reversed sublist
        prev->next->next = curr;
        prev->next = prevNode;

        return dummy.next;
    }
};