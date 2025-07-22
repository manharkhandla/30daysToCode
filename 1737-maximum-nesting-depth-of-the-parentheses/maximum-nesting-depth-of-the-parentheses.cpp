class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        stack<char> st;
        int count = 0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
                count  = max(count,(int)st.size());
            }
            else if(s[i]==')')
            {
                st.pop();
            }
        }

        return count;
    }
};