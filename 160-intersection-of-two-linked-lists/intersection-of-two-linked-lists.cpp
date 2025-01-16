/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        // Find the lengths of both lists
        int lenA = 0, lenB = 0;
        ListNode* curr = headA;

        while (curr != NULL) 
        {
            lenA++;
            curr = curr->next;
        }

        curr = headB;
        while (curr != NULL) 
        {
            lenB++;
            curr = curr->next;
        }

        // Align the start of both lists
        int diff = abs(lenA - lenB);
        if (lenA > lenB) 
        {
            while (diff--) 
            {
                headA = headA->next;
            }
        } 
        else 
        {
            while (diff--) 
            {
                headB = headB->next;
            }
        }

        // Traverse both lists together
        while (headA != NULL && headB != NULL) 
        {
            if (headA == headB) 
            {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }

        return NULL; // No intersection
    }
};