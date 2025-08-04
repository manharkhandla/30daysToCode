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
 #include<unordered_map>
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,bool> m;
        int n = nums.size();
        int max = nums[0];
        
        for(int i = 0 ;i<n ;i++){
            m[nums[i]] = true;
        }

        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp != nullptr){
            if(m[temp->val]){
                if(head == temp){
                    head = head->next;
                } 
                else{
                    prev->next = temp->next;
                }
            }else{
                prev = temp;
            }
            
            temp = temp->next;
        }


        // for (int i = 0; i < n; i++) {
        //     ListNode* temp = head;
        //     ListNode* prev = nullptr;

        //     while (temp) {
        //         if (temp->val == nums[i]) {
        //             if(temp == head) 
        //             {
        //                 head = head->next;
        //                 temp = head;
        //             } 
        //             else
        //             {
        //                 prev->next = temp->next;
        //                 temp = temp->next;
        //             }
        //         }
        //         else
        //         {
        //             prev = temp;
        //             temp = temp->next;
        //         }
        //     }
        // }
        return head;
    }
};
