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
    ListNode* mergeNodes(ListNode* head) 
    {
        ListNode* curr = head->next; // Start after the initial zero
        ListNode* newHead = new ListNode(0); // Dummy head for the new list
        ListNode* newTail = newHead; // Tail pointer for adding new nodes
        int sum = 0;

        while (curr) 
        {
            if (curr->val == 0) 
            {
                // When encountering 0, create a new node with the sum
                newTail->next = new ListNode(sum);
                newTail = newTail->next;
                sum = 0; // Reset the sum for the next segment
            } 
            else 
            {
                sum += curr->val; // Accumulate values
            }

            curr = curr->next; // Advance the pointer
        }

        return newHead->next; // Skip the dummy head
    }
};