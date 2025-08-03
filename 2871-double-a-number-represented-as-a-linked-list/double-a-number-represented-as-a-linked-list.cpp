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
    ListNode* doubleIt(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        string s = "";

        while(temp)
        {
            n++;
            s+= to_string(temp->val);
            temp=temp->next;
        }

        string s2 = "";
        int carry = 0;

        for (int i = s.length() - 1; i >= 0; i--) {
            int digit = (s[i] - '0') * 2 + carry;
            s2 += (digit % 10) + '0';
            carry = digit / 10;
        }

        if (carry) s2 += carry + '0';
        reverse(s2.begin(), s2.end());

        temp = head;
        for(int i=0;i<n-1;i++)
        {
            temp->val = s2[i] - '0';
            temp=temp->next;
        }

        temp->val = s2[n-1] - '0';

        if(n!=s2.size())
        {
            ListNode* new_node =new ListNode(s2[n] - '0');
            temp->next = new_node;
            return head;
        }
        return head;

    }
};