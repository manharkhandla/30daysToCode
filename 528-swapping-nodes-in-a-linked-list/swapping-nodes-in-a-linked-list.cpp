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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        ListNode* temp = head;

        
        for (int i = 1; i < k; ++i) {
            temp = temp->next;
        }
        temp1 = temp;

        
        while (temp->next) {
            temp = temp->next;
            temp2 = temp2->next;
        }


        swap(temp1->val, temp2->val);
        return head;
    }
};
