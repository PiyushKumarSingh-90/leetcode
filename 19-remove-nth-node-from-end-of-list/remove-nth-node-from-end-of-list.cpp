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

        // 1️⃣ Count length
        while (temp)
        {
            count++;
            temp = temp->next;
        }

        // 2️⃣ If head needs to be removed
        if (n == count)
        {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // 3️⃣ Reach node before the one to delete
        int removePos = count - n;
        ListNode* curr = head;

        for (int i = 1; i < removePos; i++)
        {
            curr = curr->next;
        }

        // 4️⃣ Remove node
        ListNode* del = curr->next;
        curr->next = del->next;
        delete del;

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