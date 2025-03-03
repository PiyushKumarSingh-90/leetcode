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
class Solution 
{
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if (!head || k == 1) return head;

        ListNode* temp = head;
        int count = 0;

        // Step 1: Count k nodes
        for (int i = 0; i < k; i++) {
            if (!temp) return head; // If less than k nodes remain, return as is
            temp = temp->next;
        }

        // Step 2: Reverse k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        
        for (int i = 0; i < k; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Step 3: Recursively process next group
        head->next = reverseKGroup(curr, k);

        return prev; // New head of the reversed list
    }
};