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
    ListNode* deleteDuplicates(ListNode* head) {
       ListNode* curr = head;
       ListNode* prev = head;
       bool isHead = false;
       bool isChange = false;

       while(curr)
       {
            if(curr->next && curr->val==curr->next->val)
            {
                if(curr==head  && !isHead)
                {
                    isHead = true;
                    
                }
                curr = curr->next;
                isChange = true;
                
            }
            else if(isChange)
            {
                if(isHead)
                {
                    head = curr->next;
                    curr = head;
                    isChange = false;
                    isHead = false;
                }
                else{
                prev->next = curr->next;
                curr = prev->next;
                isChange = false;
                }
                
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
       }
       return head;
    }
};