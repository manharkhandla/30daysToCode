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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* nxt = curr->next;
        head = curr;
        ListNode* ex = head;
        
        while(curr)
        {
            curr->next = prev;
            if(nxt) prev->next = nxt->next;
            else prev->next = NULL;
            curr = prev->next;
            ex = prev;
            prev = nxt;
            if(curr) nxt = curr->next;
            else break;
        }
        
        if(prev == nxt) ex->next = prev;

        return head;
    }
};