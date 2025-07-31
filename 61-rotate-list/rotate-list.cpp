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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        if(!head->next) return head;
        ListNode* temp = head;
        ListNode* prev = NULL;
        int size = 0;

        while(temp)
        {
            temp=temp->next;
            size++;
        }

        temp = head;
        k = k%size;
        
        for(int i=1;i<=k;i++)
        {
            while(temp->next)
            {
                prev = temp;
                temp=temp->next;
            }

            temp->next = head;
            head = temp;
            prev->next = NULL;
        }

        return head;
        
    }
};