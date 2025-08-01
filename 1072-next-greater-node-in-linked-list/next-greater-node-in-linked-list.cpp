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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int,int>> st;
        int n = 0;
        ListNode* p = head;
        while(p)
        {
            p=p->next;
            n++;
        }

        vector<int> ans(n,0);
        int i = 0;
        st.push({i,head->val});
        ListNode* temp = head->next;
        
        while(temp)
        {
            while(!st.empty() && temp->val > st.top().second)
            {
                ans[st.top().first] = temp->val;
                st.pop();
            }
            i++;
            st.push({i,temp->val});
            temp = temp->next;
        }

        return ans;
    }
};