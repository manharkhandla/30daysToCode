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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* prev = even;

        while(odd->next && even->next)
        {
            if(odd && odd->next)
            {
                odd->next = odd->next->next;
                odd = odd->next;
            }

            
            if(even && even->next)
            {
                even->next = even->next->next;
                even = even->next;
            }
            else even->next = NULL;
        }

        odd->next = prev;
        return head;
    }
};