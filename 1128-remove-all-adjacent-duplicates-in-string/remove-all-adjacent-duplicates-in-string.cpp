class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        st.push(s[0]);
        string ans = "";

        for(int i=1;i<s.size();i++)
        {
            if(st.empty() || st.top() != s[i]) st.push(s[i]);
            else st.pop();
        }

        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};