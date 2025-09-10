class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k==0) return nums;
        int n = nums.size();
        vector<int> ans(n,-1);
        queue<int> idx;

        int i=0,j=0;
        long long sum = 0;
        while(j<n)
        {
            sum+=nums[j];
            if (!idx.empty() && j >= idx.front() + k)
            {
                ans[idx.front()] = sum / (2 * k + 1);
                sum -= nums[i];
                i++;
                idx.pop();
            }

            if (j - k >= 0 && j + k < n)
            {
                idx.push(j);
            }

            j++;
        }
        return ans;
    }
};