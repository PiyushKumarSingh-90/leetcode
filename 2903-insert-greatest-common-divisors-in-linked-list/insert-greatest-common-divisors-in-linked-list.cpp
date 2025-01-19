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
    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
        ListNode *curr = head;

        while(curr != NULL && curr->next != NULL)
        {
            int num1 = curr->val;
            int num2 = curr->next->val;
            int gcd = __gcd(num1,num2);

            ListNode *gcdNum = new ListNode(gcd);

            gcdNum->next = curr->next;
            curr->next = gcdNum;

            if(curr->next->next != NULL)
            {
                curr = curr->next->next;
            }
        }

        return head;
    }
};