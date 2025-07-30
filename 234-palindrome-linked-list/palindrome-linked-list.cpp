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
    bool isPalindrome(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        vector<int> l1;
        vector<int> l2;
        ListNode* nxt = head->next;

        while(curr)
        {
            if(!curr->next)
            {
                l1.push_back(curr->val);
                curr->next = prev;
                break;
            } 
            l1.push_back(curr->val);
            curr->next = prev;
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
        }

        while(curr)
        {
            l2.push_back(curr->val);
            curr = curr->next;
        }

        int l1size = l1.size();
        int l2size = l2.size();

        if(l1size!= l2size) return false;

        for(int i=0;i<l1size;i++)
        {
            if(l1[i] != l2[i]) return false;
        }

        return true;
    }
};