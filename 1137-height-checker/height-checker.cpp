class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count = 0;
        int n = heights.size();
        vector<int> exp(n);

        for(int i=0;i<n;i++)
        {
            exp[i] = heights[i];
        }

        sort(exp.begin(),exp.end());

        for(int i=0;i<n;i++)
        {
            if(exp[i]!=heights[i]) count++;
        }

        return count;
    }
};