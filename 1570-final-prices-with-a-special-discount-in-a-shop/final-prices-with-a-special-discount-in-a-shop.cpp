class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(0);
        int tp;

        for(int i=0;i<n;i++)
        {
            ans[i] = prices[i];
        }

        for(int i=1;i<n;i++)
        {
            while(!st.empty() && prices[i]<=prices[st.top()])
            {
                tp = st.top();
                ans[tp] = prices[tp] - prices[i];
                st.pop();  
            }
            st.push(i);
        }

        return ans;
    }
};