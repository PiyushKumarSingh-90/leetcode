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
    bool isPalindrome(ListNode* head) 
    {
        if (!head) return true; // Handle empty list

        // Initialize curr to head
        stack<int> s;
        ListNode* curr = head;

        // Push all elements of the linked list into the stack
        while (curr != NULL)
        {
            s.push(curr->val);
            curr = curr->next;
        }

        // Compare the stack elements with the linked list values
        while (head && !s.empty())
        {
            if (s.top() != head->val) 
                return false; // Not a palindrome
            s.pop();
            head = head->next;
        }

        return true;
    }
};