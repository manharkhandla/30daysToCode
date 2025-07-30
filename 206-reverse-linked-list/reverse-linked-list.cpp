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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        if(!head) return head;
        ListNode* nxt = head->next;

        while(curr)
        {
            if(!curr->next)
            {
                curr->next = prev;
                break;
            } 
            curr->next = prev;
            prev = curr;
            curr = nxt;
            nxt = nxt->next;

        }
        return curr;
    }
};