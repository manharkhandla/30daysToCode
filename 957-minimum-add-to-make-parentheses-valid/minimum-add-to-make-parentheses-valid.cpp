class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int close = 0;
        int n = s.size();

        for(int i=0;i<n;i++)
        {
            if(s[i]=='(') st.push(s[i]);
            else if(s[i]==')')
            {
                if(st.empty()) close++;
                else st.pop();
            }
        }

        return st.size()+close;
    }
};