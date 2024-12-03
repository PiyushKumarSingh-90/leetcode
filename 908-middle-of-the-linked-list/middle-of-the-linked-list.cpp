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
    ListNode* middleNode(ListNode* head) 
    {
        int count = 0;
        ListNode* temp = head;

        while (temp != NULL) 
        {
            count++;
            temp = temp->next;
        }

        // Step 2: Find the middle index
        int middleIndex = count / 2;

        // Step 3: Traverse to the middle node
        temp = head; // Reset temp to head
        for (int i = 0; i < middleIndex; i++) {
            temp = temp->next;
        }

        // Step 4: Return the middle node
        return temp;
        
    }
};