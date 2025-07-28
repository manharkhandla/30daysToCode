// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(!list1 && !list2) return nullptr;
        else if(!list1) return list2;
        else if(!list2) return list1;

        ListNode* p1 = list1;
        ListNode* p2 = list2;
        ListNode* prev = nullptr;
        int less = list1->val <= list2->val ? 1 : 2;
        if(less == 1) prev = p1;
        else prev = p2;
        bool flag = (less == 1);

        if(flag) 
        {
            while(p1!=NULL && p2!=NULL) {
                if(p1->val >= p2->val) {
                    if(p1->val == p2->val) {
                        prev = p1;
                        p1 = p1->next;
                    }
                    ListNode* temp2 = p2->next;
                    prev->next = p2;
                    p2->next = p1;
                    prev = p2;
                    p2 = temp2;
                } else {
                    prev = p1;
                    p1 = p1->next;
                }
            }
            while(p2!=NULL) {
                prev->next = p2;
                prev = p2;
                p2 = p2->next;
            }
        } 

        else 
        {
            while(p1!=NULL && p2!=NULL) {
                if(p2->val >= p1->val) {
                    if(p1->val == p2->val) {
                        prev = p2;
                        p2 = p2->next;
                    }
                    ListNode* temp1 = p1->next;
                    prev->next = p1;
                    p1->next = p2;
                    prev = p1;
                    p1 = temp1;
                } else {
                    prev = p2;
                    p2 = p2->next;
                }
            }
            while(p1!=NULL) {
                prev->next = p1;
                prev = p1;
                p1 = p1->next;
            }
            return list2;
        }

        return list1;
    }
   
};
