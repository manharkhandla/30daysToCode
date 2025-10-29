#include <bits/stdc++.h>
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<int> st;

        string ans = "";

        for(int i=0;i<n;i++)
        {
            if(s[i]=='(') st.push(i);
            else if(s[i]==')')
            {
                int l = st.top() + 1;
                st.pop();
                reverse(s.begin() + l, s.begin() + i);
            }
        }

        for(int i=0;i<n;i++) if(s[i]!='(' && s[i]!=')') ans += s[i];

        return ans;
    }
};