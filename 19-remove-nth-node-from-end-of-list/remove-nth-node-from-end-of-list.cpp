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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int count = 0;
        ListNode* temp = head;

        while(temp)
        {
            count++;
            temp = temp->next;
        }

        //if head need to remove
        if(n == count)
        {
            ListNode* newHead = head->next;
            delete head;
            
            return newHead;
        }

        int RemovePos = count - n;

        ListNode* curr = head;

        for(int i = 1; i < RemovePos; i++)
        {
            curr = curr->next;
        }

        ListNode* DelNode = curr->next;

        curr->next = DelNode->next;
        delete DelNode;

        return head;
        

        return head;
    }
};


        // ListNode *fast = head;
        // ListNode *slow = head;

        // while(n--)
        // {
        //     fast =fast->next;
        // }

        // if(fast == NULL) return slow->next;

        // while(fast->next != NULL)
        // {
        //     slow = slow->next;
        //     fast= fast->next;
        // }

        // slow->next = slow->next->next;
        // return head;