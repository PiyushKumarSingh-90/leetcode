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
    ListNode* removeElements(ListNode* head, int val) 
    {
        while (head != NULL && head->val == val) {
            ListNode* temp = head; // Store current head
            head = head->next;     // Move to the next node
            delete temp;           // Free memory
        }

        ListNode* curr = head;
        ListNode* prev = NULL;

        while (curr != NULL) {
            if (curr->val == val) {
                // Remove the current node
                if (prev != NULL) {  // Ensure prev is not NULL
                    prev->next = curr->next; // Skip the current node
                }
                ListNode* temp = curr; // Store node to delete
                curr = curr->next;     // Move to the next node
                delete temp;           // Free memory
            } else {
                // Move pointers forward
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};