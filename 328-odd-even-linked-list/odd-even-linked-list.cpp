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
        if(head==NULL || head->next==NULL) return head;
        ListNode* c = head;
        ListNode* n = head->next;
        ListNode* temp = n;
        int count = 0;

        while(n->next!=NULL)
        {
            c->next = n->next;
            c = n;
            n = n->next;
            count++;
        }

        if(count%2!=0)
        {
            c->next = NULL;
            n->next = temp;
            return head;
        }

        c->next = temp;
        return head;
    }
};