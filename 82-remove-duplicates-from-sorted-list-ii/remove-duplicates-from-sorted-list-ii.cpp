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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if (!head) return nullptr; 

        ListNode* dummy = new ListNode(0); 
        dummy->next = head;
        ListNode* prev = dummy; 

        while (head) 
        {
            if (head->next && head->val == head->next->val) 
            {
                // Move to the last duplicate
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                // Remove all duplicates
                prev->next = head->next;
            } else {
                // Move prev forward if no duplicate
                prev = prev->next;
            }
            head = head->next; // Move head forward
        }

        return dummy->next; // Return the updated list
    }
};