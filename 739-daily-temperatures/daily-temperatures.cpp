class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n,0);
        st.push(0);

        for(int i=1;i<n;i++)
        {
            while(!st.empty() && temperatures[i]>temperatures[st.top()])
            {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};